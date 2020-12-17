#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////
// AdornmentPolicy Classes (3)

class Adornment_Policy_Text
{
protected:
    template< typename message_type >
    message_type Decorate( message_type message )
    {
        return message;
    }
};

class Adornment_Policy_HTML
{
protected:
    template< typename message_type >
    message_type Decorate( message_type message )
    {
		message_type start("<h1>");
    	message_type end("</h1>");
		return start + message + end;
    }
};

class Adornment_Policy_XML
{
protected:
    template< typename message_type >
    message_type Decorate( message_type message )
    {
		message_type start("<out::doc xmlns='http://mydoc.com'>");
		message_type end("</out::doc>");
		return start + message + end;
    }
};

////////////////////////////////////////////////////////////
// OutputPolicy Classes (3)

class OutputPolicy_WriteToCout
{
protected:
    template< typename message_type >
    void Print( message_type message )
    {
        cout << message << endl;
    }
};

class OutputPolicy_WriteToCerr
{
protected:
    template< typename message_type >
    void Print( message_type message )
    {
		cerr << "Error: " << message << endl;
    }
};

class OutputPolicy_Logging
{
protected:
    template< typename message_type >
    void Print( message_type message, const string& logfile )
    {
		cout << "Writing to: " << logfile << endl;
		cout << message << endl;
    }
};


////////////////////////////////////////////////////////////
// LanguagePolicy Classes (3)

class English {};
class French {};
class German {};

template <class LANGUAGE>
struct LanguagePolicy;

template <>
struct LanguagePolicy<English>
{
    std::string Message()
    {
		return "Hello, World!";
    }
};

template <>
struct LanguagePolicy<French>
{
    std::string Message()
    {
		return "Bonjour, Monde!";
    }
};

template <>
struct LanguagePolicy<German>
{
    std::string Message()
    {
		return "Hallo Welt!";
    }
};


////////////////////////////////////////////////////////////
// Policy template (3 * 3 * 3 = 27 possibilities)

template <
          typename adornment_policy,
          typename output_policy,
		  typename language >
class HelloWorld : public adornment_policy,
                   public output_policy,
                   public LanguagePolicy<language>
{
    using adornment_policy::Decorate;
    using output_policy::Print;
    using LanguagePolicy<language>::Message;
public:
    // note methods can have different signatures
    void Run()
    {
        Print(Decorate(Message()));
    }

    void Run(const string& logfile)
    {
		Print(Decorate(Message()), logfile);
    }
};

////////////////////////////////////////////////////////////

int main()
{
    HelloWorld<Adornment_Policy_Text, OutputPolicy_WriteToCout, English> t1;
    HelloWorld<Adornment_Policy_HTML, OutputPolicy_WriteToCout, German>  t2;
    HelloWorld<Adornment_Policy_XML,  OutputPolicy_WriteToCerr, French>  t3;
    HelloWorld<Adornment_Policy_XML,  OutputPolicy_Logging,     English> t4;

    t1.Run();
    t2.Run();
    t3.Run();
    t4.Run("myLogFile");
}
