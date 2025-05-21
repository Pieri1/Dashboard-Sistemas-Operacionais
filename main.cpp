// Inclui bibliotecas necessarias.
#include <iostream>
#include <dirent.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

// Verifica se a string é um número.
bool is_number(const char* str) {
    for (int i = 0; str[i]; ++i)
        if (!isdigit(str[i])) return false;
    return true;
}

// Função principal do programa.
int main() {
    DIR* proc = opendir("/proc");
    if (!proc) {
        perror("opendir");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(proc)) != nullptr) {
        if (entry->d_type == DT_DIR && is_number(entry->d_name)) {
            std::cout << "PID: " << entry->d_name;
            char status_path[256];
            snprintf(status_path, sizeof(status_path), "/proc/%s/status", entry->d_name);
            FILE* status_file = fopen(status_path, "r");
            if (status_file) {
                char line[256];
                while (fgets(line, sizeof(line), status_file)) {
                    if (strncmp(line, "Nome:", 5) == 0) {
                        std::cout << " | " << line;
                        break;
                    }
                }
                fclose(status_file);
            } else {
                std::cout << " | (Sem acesso ao Status)";
            }
        }
    }
    closedir(proc);
    return 0;
}