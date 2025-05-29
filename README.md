# Repositório de arquivos no github: https://github.com/Pieri1/Dashboard-Sistemas-Operacionais

# ✅ Checklist de Progresso – Projeto A (Dashboard)

## 🎯 Funcionalidades Principais

### 🔹 Monitoramento de Processos
- [X] Exibir dados globais do processador (uso da CPU, tempo ocioso)
- [X] Exibir total de processos e threads em execução
- [X] Listar todos os processos existentes
- [X] Mostrar o usuário associado a cada processo
- [X] Mostrar informações sobre os threads de cada processo
- [X] Mostrar informações detalhadas por processo (em tela ou aba separada)

### 🔹 Monitoramento de Memória
- [X] Exibir uso global da memória RAM (usada, livre, percentual)
- [X] Exibir uso de memória virtual (swap)
- [X] Exibir informações detalhadas de memória por processo:
  - [X] Total de memória alocada
  - [X] Páginas de memória (total, código, heap, stack)
- [X] Detalhamento em tela ou aba separada (com botão de retorno à tela principal)

---

## ⚙️ Requisitos Técnicos Obrigatórios

- [X] Atualizar os dados automaticamente a cada 5 segundos
- [X] Permitir visualizar informações globais e individuais dos processos
- [X] Apresentar dados processados (nada de saída crua)
- [X] Não usar comandos shell como `ps`, `ls`, `du`, etc
- [X] Utilizar APIs ou leitura direta do sistema operacional (ex: `/proc` no Linux)
- [X] Implementar o projeto com **software multitarefa** (ex: threads)
- [X] Seguir o padrão de projeto **MVC (Model-View-Controller)**