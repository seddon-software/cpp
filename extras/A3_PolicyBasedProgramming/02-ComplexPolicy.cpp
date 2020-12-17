#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////
// AdornmentPolicy Templates (3)

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
// OutputPolicy Templates (3)

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
// LanguagePolicy Templates (3)

class LanguagePolicy_English
{
 protected:
    std::string Message()
    {
        return "Hello, World!";
    }
};

class LanguagePolicy_French
{
 protected:
    std::string Message()
    {
        return "Bonjour, Monde!";
    }
};

class LanguagePolicy_German
{
 protected:
    std::string Message()
    {
        return "Hallo Welt!";
    }
};

////////////////////////////////////////////////////////////
// Policy Templates (27)

template <typename adornment_policy,
          typename output_policy,
          typename language_policy>
class HelloWorld : public adornment_policy,
                   public output_policy,
                   public language_policy
{
    using adornment_policy::Decorate;
    using output_policy::Print;
    using language_policy::Message;
public:
    void Run()
    {
        Print(Decorate(Message()));
    }

    void Run(const string& logfile)
    {
		Print(Decorate(Message()), logfile);
    }
};

// partial specialization
/*
template <typename adornment_policy,
          typename language_policy>
class HelloWorld<adornment_policy, OutputPolicy_Logging, language_policy>
	: public adornment_policy,
                   public OutputPolicy_Logging,
                   public language_policy
{
    using adornment_policy::Decorate;
    using OutputPolicy_Logging::Print;
    using language_policy::Message;

public:
    void Run(const string& logfile)
    {
		Print(Decorate(Message()), logfile);
    }
};
*/

////////////////////////////////////////////////////////////

int main()
{
    /* example 1 */
    HelloWorld<Adornment_Policy_Text, OutputPolicy_WriteToCout, LanguagePolicy_English> t1;
    HelloWorld<Adornment_Policy_HTML, OutputPolicy_WriteToCout, LanguagePolicy_German>  t2;
    HelloWorld<Adornment_Policy_XML,  OutputPolicy_WriteToCerr, LanguagePolicy_French>  t3;
    HelloWorld<Adornment_Policy_XML,  OutputPolicy_Logging,     LanguagePolicy_English> t4;
    t1.Run();
    t2.Run();
    t3.Run();
    t4.Run("myLogFile");
}
