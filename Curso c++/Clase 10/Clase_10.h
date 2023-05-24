std::string latin1_to_utf8(const std::string_view &latin1);
std::string utf8_to_latin1(const std::string_view &utf8);

bool es_primo(int n);
void primos_en_binario(int cantidad);
void primos_en_decimal(int cantidad);
void primos_en_hexa(int cantidad);

int count_utf8_glyphs(const std::string_view &utf8);
void diacritic_tolower(unsigned char &c);
bool comparar_ignorando_diacriticos(char caracter_1, char caracter_2);
bool is_equal(const std::string_view &str1, const std::string_view &str2);