class string
{
    private:
        char* ptr;
        unsigned length;
        unsigned size;
    public:
        string();
        string(const char* s);
        string(const string &s);
        string(char c, unsigned times);
        ~string();

        void set_string(const char* s);
        void set_string(const string &s);

        const char* get_string() const { return ptr;} 
        unsigned get_length() const { return length;}
        unsigned get_size() const { return size;}

        void append(const char* s);
        void append(const string &s);
        void append(const char c);

        void swap(string &s);

        bool is_equal(const char* s) const;
        bool is_equal(const string &s) const;
        bool contains(const char* s) const;
        void invert_case();
        
        string &operator=(const string &right);
        string &operator=(const char *right);

        string &operator+=(const char *s);
        string &operator+=(const string &s);
        string &operator+=(char c);

        bool operator==(const string &right) const;
        bool operator==(const char *right) const;
        bool operator!=(const string &right) const;
        bool operator!=(const char *right) const;

        string substring(unsigned from, unsigned length) const;

};

void print_screen(const string &s);
void print_screen(const char *s);

string operator+(const string &left, const char *right);
string operator+(const char *left, const string &right);
string operator+(const string &left, const string &right);




