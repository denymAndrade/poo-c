 #ifndef ELETRONICO_H
 #define ELETRONICO_H

 #include "produto.h"

 class Eletronico : public Produto {
 private:
	 int garantiaMeses; // atributo específico

 public:
	 Eletronico(const std::string& nome = "", double valor = 0.0, int garantia = 0);
	 ~Eletronico() override;

	 void setGarantia(int meses);
	 int getGarantia() const;

	 void mostrar() const override;
 };

 #endif // ELETRONICO_H
