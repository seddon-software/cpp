from inspect import stack
import os, sys
import curses
import time
import __main__

stdscr = curses.initscr()

class TooBig(Exception):
    pass

def debug(text):
    output(1, 60, str(text), curses.color_pair(6))
    refresh()
    time.sleep(1)
    output(1, 60, " "*len(text), curses.color_pair(6))

def start():
    curses.curs_set(0)
    curses.noecho()
    curses.raw()
    Color()


def finish():
    stdscr.keypad(False)
    curses.echo()
    curses.endwin()
    sys.exit()

def wait():    
    if not os.environ.get('TERM_PROGRAM') == "vscode": 
        ch = stdscr.getch()
        if ch == 3: finish()    # terminate on Ctl-C
    refresh()
    
def refresh():
    stdscr.refresh()

def output(row, col, text, color=None):
    try:
        if color == None: color = curses.color_pair(1)
        stdscr.addstr(row, col, text, color)
        row += 1
    except Exception as e:
        if not os.environ.get('TERM_PROGRAM') == "vscode": 
            # print(e)
            pass
    return row

def label(row, col, text):
    stdscr.addstr(row, col, text, curses.color_pair(1))

class Code:
    '''
    self.index = index of code line
    self.row = screen row of start line of code 
    '''
    def __init__(self, row, col, lineNumbers=False):
        def add_line_numbers():
            for n, line in enumerate(self.code):
                self.code[n] = f"{n+1:2}: {line}"
        code = __main__.__doc__
        self.row_const = row
        self.col_const = col
        self.code = code.split("\n")
        if lineNumbers: 
            add_line_numbers()
        self.index = 0
        self.previous_row = None
        self.show()
        self.lineNumbers = lineNumbers
        self.messages = {}
    
    def set_message_area(self, row, col):
        self.message_row = row
        self.message_col = col
        self.size = 1 
        
    def show(self):
        row = self.row_const
        for line in self.code:
            row = output(row, self.col_const, line, curses.color_pair(1))
        refresh()

    def __call__(self, index, message=""):
        index = index - 1

        # clear message
        if message != "":
            output(self.message_row, self.message_col, " "*self.size, curses.color_pair(6))
        if index != -1:
            # goto required code line
            col = self.col_const
            if(self.previous_row): output(self.previous_row, col, self.previous_line, curses.color_pair(1))
            self.index = index
            new_row = self.index + self.row_const
            try:
                line = self.code[self.index]
                output(new_row, self.col_const, line, Thread.current_thread.get_color())
                self.previous_row = new_row
                self.previous_line = self.code[self.index]
            except Exception as e:
                output(self.message_row, self.message_col, e.__str__(), curses.color_pair(6))
#            wait()
        

        # display messages
        if not message == "":
            output(self.message_row, self.message_col, message, curses.color_pair(6))
            refresh()
            self.size = max(self.size, len(message))
        wait()

    def step(self, rows=1):
        col = self.col_const
        if(self.previous_row): output(self.previous_row, col, self.previous_line, curses.color_pair(1))
        self.index += rows
        new_row = self.index + self.row_const
        try:
            line = self.code[self.index]
            output(new_row, self.col_const, line, Thread.current_thread.get_color())
            self.previous_row = new_row
            self.previous_line = self.code[self.index]
            refresh()
#            wait()
        except:
            pass    # no more code

class Color:
    def __init__(self):
        try:
            curses.start_color()
            if(not curses.has_colors()): raise Exception()
        except Exception as e:
            print("no colors")
            sys.exit(1)
        curses.init_color(31, 0, 1000, 0)
        curses.init_color(32, 0,  700, 300)
        curses.init_color(41, 1000, 0, 0)
        curses.init_color(42, 700, 300, 0)
        curses.init_color(99, 0, 0, 1000)
        
        curses.init_pair(1, curses.COLOR_WHITE, curses.COLOR_BLACK)
        curses.init_pair(2, 31, curses.COLOR_BLACK)
        curses.init_pair(3, 32, curses.COLOR_BLACK)
        curses.init_pair(4, 41, curses.COLOR_BLACK)
        curses.init_pair(5, 42, curses.COLOR_BLACK)
#        curses.init_pair(6, curses.COLOR_RED, curses.COLOR_YELLOW)
        curses.init_pair(6, 99, curses.COLOR_YELLOW)
        stdscr.bkgd(0, curses.color_pair(1))

class Thread:
    current_thread = None

    def __init__(self, color1, color2):
        self.color1 = color1
        self.color2 = color2
        self.current_color = color1
        self.activate()

    def activate(self):
        Thread.current_thread = self

    def swap_colors(self):
        if self.current_color == self.color1:
            self.current_color = self.color2
        else:
            self.current_color = self.color1

    def get_color(self):
        return curses.color_pair(self.current_color)

class Stack:
    ''' work to do if stack v=can be wider than 11'''
    def __init__(self, row, col, boxes, width=11):
        self.row = row
        self.col = col
        self.boxes = boxes
        self.variables = []
        self.draw_stack()
        self.width = 11

    def draw_stack(self):
        boxes = self.boxes
        row = self.row
        col = self.col 
        row = output(row, col, "┌─────────┐");
        for i in range(boxes-1):
            row = output(row, col, "│         │");
            row = output(row, col, "├─────────┤");
        row = output(row, col, "│         │");
        row = output(row, col, "└─────────┘");

    def add(self, variable):
        self.variables.append(variable)
    
    def rowOffset(self, variable):
        index = self.variables.index(variable)
        return 2*index + 1

class Variable:
    def __init__(self, name, stack, value):
        self.name = name
        self.stack = stack
        self.value = value
        self.hasArrow = False
        stack.add(self)
    
    def set(self, rhs):
        '''sets variable and updates screen'''
        if isinstance(rhs, Variable):
            self.value = rhs.value
        else:
            self.value = rhs
        try:
            self.print()
        except:
            pass

    def getRowOffset(self):
        return self.stack.rowOffset(self)

    def print(self, hide=False):
        '''prints the value on screen'''
        stack = self.stack
        width = stack.width
        row = stack.row + self.getRowOffset()
        col = stack.col + width//2 - 4
        blanks = " "*7
        output(row, col, blanks)
        refresh()
        if not hide: output(row, col, str(self.value), Thread.current_thread.get_color())
        refresh()

    def show_and_print(self):
        self.show()
        self.print()

    def show(self):
        '''displays variable on screen'''
        stack = self.stack
        width = stack.width
        row = stack.row + self.getRowOffset()
        col = stack.col + width + 1
        output(row, col, self.name)

    def hide_and_wait(self):
        self.hide()
        wait()

    def remove(self):
        self.hide()
        stack = self.stack
        stack.variables.pop()

    def hide(self):
        stack = self.stack
        width = stack.width
        row = stack.row + self.getRowOffset()
        col = stack.col + width + 1
        blanks = " "*len(self.name)
        output(row, col, blanks)
        refresh()
        self.print(hide=True)
        if self.hasArrow:
            self.arrow(self.to, hide=True)

    def arrow(self, to, hide=False):
        if (self.stack.row + self.getRowOffset()) == (to.stack.row + to.getRowOffset()):
            self.arrowStraight(to, hide)
        else:
            self.arrowDogLeg(to, hide)
        if hide:
            self.hasArrow = False

    
    def arrowStraight(self, to, hide=False):
        self.hasArrow = True
        self.to = to
        row = to.stack.row + to.getRowOffset()
        col = self.stack.col + self.stack.width + len(self.name) + 1
        count = to.stack.col - self.stack.col - self.stack.width - len(self.name) - 2
        if hide:
            text = " "*(count+1)
        else:
            text = "─"*count + "➤"
        output(row, col, text, curses.color_pair(1))

    def arrowDogLeg(self, to, hide=False):
        self.hasArrow = True
        self.to = to
        to_row = to.stack.row + to.getRowOffset()
        self_row = self.stack.row + self.getRowOffset()
            
        col = self.stack.col + self.stack.width + len(self.name) + 1
        count = to.stack.col - self.stack.col - self.stack.width - len(self.name)

        leftCount = count//2
        rightCount = count-leftCount

        if not hide:
            if self_row > to_row:
                direction = "up"
            else:
                direction = "down"
            elbow = "┐" if direction == "down" else "┘"    
            leftText = "─"*(leftCount-1) + elbow
            elbow = "└" if direction == "down" else "┌"    
            rightText = elbow + "─"*(rightCount-2) + "➤"
            output(self_row, col, leftText, curses.color_pair(1))
            while self_row != to_row:
                if self_row > to_row:
                    output(self_row-1, col+leftCount-1, "│", curses.color_pair(1))
                    self_row -= 1
                else:
                    output(self_row+1, col+leftCount-1, "│", curses.color_pair(1))
                    self_row += 1

            output(to_row, col+leftCount-1, rightText, curses.color_pair(1))
        else:
            leftText = " "*(leftCount-1) + " "
            rightText = " " + " "*(rightCount-2) + " "
            output(self_row, col, leftText, curses.color_pair(1))
            refresh()
            while self_row != to_row:
                if self_row > to_row:
                    output(self_row-1, col+leftCount-1, " ", curses.color_pair(1))
                    self_row -= 1
                else:
                    output(self_row+1, col+leftCount-1, " ", curses.color_pair(1))
                    self_row += 1

            output(to_row, col+leftCount-1, rightText, curses.color_pair(1))
            refresh()

