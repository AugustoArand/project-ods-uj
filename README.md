# ODS N° 04 — Sistema de Gerenciamento de Livros

Este documento detalha a arquitetura utilizada no desenvolvimento de um sistema de gerenciamento de livros para atendimento de uma solução sustentável prevista um dos 17 objetivos da ODS. Bem como, demonstra casos de uso da perspectiva do stakeholder que consumirá o projeto.

## Stakeholders
- **Usuário**: Bibliotecária responsável pelo atendimendo no balcão.
- **Administrador**: Responsável pelo gerenciamento dos livros.

---

## Banco de Dados
- Devido a dimensão do projeto, foi optado por utilizar um banco de dados local com 10 livros já pré escolhidos para serem carregados, e testar os requisitos funcionais do projeto.

---

## Requisitos Funcionais
- Deve ser possível listar todos os livros
- Deve ser possível adicionar novos livros
- Deve ser possível remover livros existentes
- Deve ser possível alterar o título de um livro já existente
- Deve ser possível realizar um empréstimo de um livro

---
## Regra de Negócio
- O usuário não pode cadastrar livros com o mesmo titulo ou autor
- O usuário não deve deixar de preencher campos obrigatórios no cadastro e alteração de titulo dos livros
- O usuário deve selecionar um livro existente para a sua remoção
- O usuário deve possuir a opção de cancelar ou sair dos menus conforme navegação

---

## Requisitos Não Funcionais
- O sistema deve prover respostas de navegação entre os menus com um tempo máximo de 1 seg
- O sistema deve voltar a listagem de livros original ao ser fechado

---


## Caso de Uso 1: Listar Livros

**Descrição:**  
Permite ao usuário visualizar todos os livros cadastrados no sistema.

**Ator Principal:**  
Usuário

**Fluxo Principal:**
1. O usuário seleciona a opção "Listar Livros" no menu.
2. O sistema exibe uma lista com todos os livros cadastrados, apresentando informações relevantes como título e identificador.

**Fluxo Alternativo:**
- Se não houver livros cadastrados, o sistema informa que a lista está vazia.

---

## Caso de Uso 2: Cadastrar Novo Livro

**Descrição:**  
Permite ao administrador adicionar um novo livro ao sistema.

**Ator Principal:**  
Administrador

**Fluxo Principal:**
1. O Administrador seleciona "Cadastrar Novo Livro" no menu.
2. O sistema solicita as informações necessárias: Nome do livro e autor.
3. O usuário informa os dados solicitados.
4. O sistema cadastra o novo livro e confirma a inclusão.

**Fluxo Alternativo:**
- Se o usuário deixar de informar algum dado obrigatório, o sistema solicita o preenchimento.

---

## Caso de Uso 3: Remover Livro

**Descrição:**  
Permite ao administrador remover um livro do sistema.

**Ator Principal:**  
Administrador

**Fluxo Principal:**
1. O administrador escolhe "Remover Livro" no menu.
2. O sistema apresenta a lista de livros cadastrados.
3. O administrador seleciona o livro a ser removido através do prompt (via numeração).
4. O sistema pede confirmação da remoção.
5. O usuário confirma.
6. O sistema remove o livro e informa o sucesso da operação.

**Fluxo Alternativo:**
- Se o usuário cancelar a operação, o livro não é removido.
- Se o livro selecionado não existir, o sistema informa o erro.

---

## Caso de Uso 4: Editar Título do Livro

**Descrição:**  
Permite ao usuário alterar o título de um livro já cadastrado.

**Ator Principal:**  
Administrador

**Fluxo Principal:**
1. O administrador seleciona "Editar Título do Livro" no menu.
2. O sistema apresenta a lista de livros cadastrados.
3. O usuário seleciona o livro que deseja editar.
4. O sistema solicita o novo título.
5. O usuário informa o novo título.
6. O sistema atualiza o título do livro e confirma a alteração.

**Fluxo Alternativo:**
- Se o título informado já existir, o sistema solicita outro título.
- Se o usuário cancelar a operação, nenhuma alteração é feita.

---

## Caso de Uso 5: Emprestar Livro

**Descrição:**  
Permite ao usuário atualizar o status do livro no sistema de "Disponivel" para "Emprestado".

**Ator Principal:**  
Usuário

**Fluxo Principal:**
1. O usuário seleciona a opção "Emprestar Livro" através do prompt.
2. O sistema mostra todos os livros catalogados.
3. O sistema solicita a escolha do livro que deseja ser emprestado, através de uma numeração no prompt
4. O sistema realiza o empréstimo do livro caso o mesmo esteja com o status "Disponivel"
5. O sistema atualiza o status do livro para "Emprestado" após uma ação bem sucedida
6. O sistema nega o empréstimo caso o status do livro seja "Emprestado"

---

## Caso de Uso 6: Emprestar Livro

**Descrição:**  
Permite ao usuário atualizar o status do livro no sistema de "Emprestado" para "Disponivel".

**Ator Principal:**  
Usuário

**Fluxo Principal:**
1. O usuário seleciona a opção "Dar Baixa" através do prompt.
2. O sistema mostra todos os livros que estão emprestados.
3. O sistema solicita a escolha do livro que deseja dar a baixa
4. O sistema mostra uma mensagem de sucesso para a ação de devolução "Livro devolvido com sucesso!!"
5. O sistema remove o livro da listagem de livros emprestados
6. O sistema atualiza o status do livro de "Emprestado" para "Disponivel"
7. O sistema deve mostrar o livro na listagem principal após está ação
   
---

## Caso de Uso 7: Sair

**Descrição:**  
Permite ao usuário encerrar o uso do sistema de forma segura.

**Ator Principal:**  
Usuário

**Fluxo Principal:**
1. O usuário seleciona "Sair" no menu.
2. O sistema encerra a aplicação.

---

## Observações Gerais

- O sistema deve validar todas as entradas de dados do usuário.
- Todas as operações devem apresentar mensagens claras de sucesso ou erro.
- O sistema deve garantir a integridade e consistência das informações dos livros cadastrados.

