
struct string_register
{
    char* ptr;
    unsigned size, length, users;

    string_register()
    {

    }
    string_register(const string_register &s)
    {
        ptr = s.ptr;
        size = s.size;
        length = s.length;
        users = s.users;
    }
};

class string
{
    //RAII: Resource Adquisition is Inicialization.
    // Si mi clase maneja, en este caso un puntero, nunca puede estar en nullptr.
    public:
        string(); 
        string(const char *s);
        string(const string &s); //Constructor de copia !!
        string(string &&rvalue);

        ~string(); //Destructor.

        void set_string(const char* s);
        void set_string(const string &s);

        void append(const char* s);
        void append(const string &s);

        string &operator=(const string &s); //Si no lo creo, el compilador se lo inventa, pero copiando propiedad por propiedad.
        string &operator=(const char *s);

        string operator+(const string &s) const;
        string operator+(const char *s) const;

        string &operator+=(const string &s);
        string &operator+=(const char *s);

        string_register *get_registro() const { return registro;}
    private:
        string_register* registro;
        unsigned len(const char* s);
};
