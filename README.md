# ✅ Checklist de Progresso – Projeto A (Dashboard)

## 🎯 Funcionalidades Principais

### 🔹 Monitoramento de Processos
- [ ] Exibir dados globais do processador (uso da CPU, tempo ocioso)
- [ ] Exibir total de processos e threads em execução
- [X] Listar todos os processos existentes
- [X] Mostrar o usuário associado a cada processo
- [X] Mostrar informações sobre os threads de cada processo
- [ ] Mostrar informações detalhadas por processo (em tela ou aba separada)

### 🔹 Monitoramento de Memória
- [ ] Exibir uso global da memória RAM (usada, livre, percentual)
- [ ] Exibir uso de memória virtual (swap)
- [ ] Exibir informações detalhadas de memória por processo:
  - [ ] Total de memória alocada
  - [ ] Páginas de memória (total, código, heap, stack)
- [ ] Detalhamento em tela ou aba separada (com botão de retorno à tela principal)

---

## ⚙️ Requisitos Técnicos Obrigatórios

- [X] Atualizar os dados automaticamente a cada 5 segundos
- [ ] Permitir visualizar informações globais e individuais dos processos
- [ ] Apresentar dados processados (nada de saída crua)
- [X] Não usar comandos shell como `ps`, `ls`, `du`, etc
- [X] Utilizar APIs ou leitura direta do sistema operacional (ex: `/proc` no Linux)
- [ ] Implementar o projeto com **software multitarefa** (ex: threads)
- [X] Seguir o padrão de projeto **MVC (Model-View-Controller)**