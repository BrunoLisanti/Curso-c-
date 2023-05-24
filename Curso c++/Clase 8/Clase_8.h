#include "Clase_6.h"

    class impresor_fiscal
    {
        public:
            virtual void mostrar_datos()=0;
    };

    class impresor_fiscal_1ra_Generacion : public impresor_fiscal
    {
        public:
            void mostrar_datos() override
            {
                std::cout << "Soy un printer de 1ra generacion" << std::endl;
            }
    };

    class impresor_fiscal_2da_Generacion : public impresor_fiscal
    {
        public:
            void mostrar_datos() override 
            { 
                std::cout << "2da Generacion" << std::endl;
            }
    };