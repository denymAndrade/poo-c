 #ifndef PRODUTO_H
 #define PRODUTO_H

 #include <string>

 class Produto {
 protected:
	 std::string nome;
	 double valor;

 public:
	 Produto(const std::string& nome = "", double valor = 0.0);
	 virtual ~Produto();

	 void setNome(const std::string& n);
	 std::string getNome() const;

	 void setValor(double v);
	 double getValor() const;

	 virtual void mostrar() const;
 };

 #endif // PRODUTO_H
