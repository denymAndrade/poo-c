 #ifndef LIVRO_H
 #define LIVRO_H

 #include "produto.h"
 #include <string>

 class Livro : public Produto {
 private:
	 std::string autor;

 public:
	 Livro(const std::string& nome = "", double valor = 0.0, const std::string& autor = "");
	 ~Livro() override;

	 void setAutor(const std::string& a);
	 std::string getAutor() const;

	 void mostrar() const override;
 };

 #endif // LIVRO_H
