#include "word_process.h"
#include <iostream>

int main() {
    WordProcessor wordProcessor;
    if (!wordProcessor.OpenFiles()) {
        return 1;
    }

    wordProcessor.ProcessData();
    wordProcessor.WriteOutput();
    wordProcessor.WriteProtocol();
    wordProcessor.CloseFiles();

    std::cout << "Обробка завершена. Перевірте файли inp.txt, out.txt та prot.txt." << std::endl;

    return 0;
}
