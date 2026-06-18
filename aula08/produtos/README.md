Exercicio POO - Produtos

Como compilar (requer g++):

```powershell
g++ -std=c++17 *.cpp -o produtos
./produtos
```

Descrição:

- `Produto` é a classe base com `nome` e `valor`.
- `Livro` e `Eletronico` herdam de `Produto` e adicionam `autor` e `garantiaMeses` respectivamente.
- `main.cpp` contém um menu para criar, listar e remover produtos.
