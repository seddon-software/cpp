////////////////////////////////////////////////////////////
//
//  Abstract Factory
//
////////////////////////////////////////////////////////////


class Top {};
class GlassTop : public Top {};
class WoodTop : public Top {};
class Legs {};
class MetalLegs : public Legs {};
class WoodLegs : public Legs {};


class TableFactory
{
public:
    virtual Top* makeTop() = 0;
    virtual Legs* makeLegs() = 0;
};

class CoffeeTableFactory : public TableFactory
{
public:
    virtual Top* makeTop() { return new GlassTop(); }
    virtual Legs* makeLegs() { return new MetalLegs(); }
};
class DiningTableFactory : public TableFactory
{
public:
    virtual Top* makeTop() { return new WoodTop(); }
    virtual Legs* makeLegs() { return new WoodLegs(); }
};

class Table
{
public:
    Table(Top* pTop, Legs* pLegs) : pTop(pTop), pLegs(pLegs) {}
private:
    Top* pTop;
    Legs* pLegs;
};

Table* CreateTable(TableFactory& factory)
{
    return new Table(factory.makeTop(), 
                     factory.makeLegs());
}

int main()
{
    CoffeeTableFactory coffeeTableFactory ;
    DiningTableFactory diningTableFactory;
    
    Table* coffeeTable = CreateTable(coffeeTableFactory);
    Table* diningTable = CreateTable(diningTableFactory);
}


