#include <iostream>
using namespace std;
#include "filas.h"

int main() {
  string comandoEntrada;
  FilaNormal filaNormal;
  FilaPreferencial filaPreferencial;
  string nome;
  int idade;
  int opcao;
  while (1) {
    cout << "Escolha uma operação" << endl;
    cout << "1 - Adicionar paciente" << endl;
    cout << "2 - Atender/Verificar" << endl;
    cout << "Outro - Sair" << endl;
    cin >> opcao;
    if (opcao == 1) {
      cout << "Digite o comando completo. ADICIONAR <nome> <idade>" << endl;
      cin >> comandoEntrada >> nome >> idade;
    } else if (opcao == 2) {
      cout << "Digite ATENDER ou VERIFICAR" << endl;
      cin >> comandoEntrada;
    } else {
      return 0;
    }
    if (comandoEntrada == "ADICIONAR") {
      if (idade >= 60) {
        filaPreferencial.adicionar(nome);
      } else {
        filaNormal.adicionar(nome);
      }
    }

    if (comandoEntrada == "ATENDER") {
      if (filaPreferencial.fim > 0) {
        filaPreferencial.atender();
      } else {
        filaNormal.atender();
      }
    }

    if (comandoEntrada == "VERIFICAR") {
      filaPreferencial.verificar();
      filaNormal.verificar();
    }
  }
}