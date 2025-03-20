# Gcovr - Ferramenta de Cobertura de Código

## Sumário

1. [Introdução](#Introdução)
2. [Funcionalidades Principais](#funcionalidades-principais)
   - [Pontos Positivos](#pontos-positivos)
   - [Pontos Negativos](#pontos-negativos)
3. [Instalação](#instalação)
   - [Linux](#linux)
   - [Windows](#windows)
   - [macOS](#macos)
   - [Verificando a Instalação](#verificando-a-instalação)
4. [Projeto de Cobertura de Código com `gcovr`](#projeto-de-cobertura-de-código-com-gcovr)
   - [Estrutura de Diretórios](#estrutura-de-diretórios)
   - [Passo a Passo](#passo-a-passo)
     - [1. Criar as Pastas](#1-criar-as-pastas)
     - [2. Mover os Arquivos-Fonte](#2-mover-os-arquivos-fonte)
     - [3. Compilar com Arquivos Organizados](#3-compilar-com-arquivos-organizados)
     - [4. Criar os Executáveis](#4-criar-os-executáveis)
     - [5. Rodar os Testes](#5-rodar-os-testes)
     - [6. Gerar o Relatório de Cobertura](#6-gerar-o-relatório-de-cobertura)
5. [Conclusão](#conclusão)

## Introdução

O `gcovr` é uma ferramenta de linha de comando essencial para desenvolvedores que desejam monitorar e melhorar a cobertura de código de seus projetos em C e C++. Utilizando os arquivos de cobertura gerados pelo `gcov` (parte do GCC), o `gcovr` produz relatórios detalhados em diversos formatos, facilitando a identificação de áreas do código que não estão sendo adequadamente testadas.

### Funcionalidades Principais

-   **Relatórios Flexíveis**: Gere relatórios em texto simples, HTML interativo ou XML para integração com ferramentas de CI/CD.
-   **Integração CI/CD**: A saída XML facilita a integração com pipelines de integração contínua, como Jenkins, GitLab CI, etc.
-   **Suporte a Projetos Grandes**: Processe múltiplos diretórios e arquivos, ideal para projetos complexos.
-   **Filtros Personalizáveis**: Inclua ou exclua arquivos e funções nos relatórios para focar nas áreas críticas.
-   **Cobertura Detalhada**: Relatórios de cobertura de linha e função para uma análise completa.
-   **Facilidade de Uso**: Ferramenta de linha de comando simples, perfeita para automação.

### Pontos Positivos

-   **Simplicidade**: Fácil de configurar e usar.
-   **Versatilidade de Relatórios**: Adapte os relatórios às suas necessidades.
-   **Visibilidade nos Testes**: Identifique áreas não testadas.
-   **Escalabilidade**: Ideal para projetos de todos os tamanhos.
-   **Compatibilidade GCC**: Integração perfeita com projetos GCC.

### Pontos Negativos

-   **Dependência do GCC**: Limitado a projetos que usam GCC.
-   **Relatórios Básicos**: Pode ser simples comparado a ferramentas mais avançadas.
-   **Integração Limitada**: Poucas integrações nativas com outras ferramentas.
-   **Análises Simples**: Menos opções de personalização e análise avançada.
-   **Desempenho em Projetos Grandes**: Pode ser lento com grandes volumes de dados.

## Instalação

### Linux

```bash
pip install gcovr
```
Ou, caso prefira instalar a versão do sistema:
```bash
sudo apt update && sudo apt install gcovr  # Para Debian/Ubuntu
sudo dnf install gcovr  # Para Fedora
sudo pacman -S gcovr  # Para Arch Linux
```

### Windows
```bash
pip install gcovr
```
Caso esteja utilizando o `MSYS2`, pode instalar com:
```bash
pacman -S mingw-w64-x86_64-gcovr  # Para sistemas de 64 bits
```

### macOS
```bash
brew install gcovr
```
Ou via `pip`:
```bash
pip install gcovr
```

### Verificando a Instalação
Após a instalação, verifique se o `gcovr` está instalado corretamente executando:
```bash
gcovr --version
```

Se a instalação foi bem-sucedida, a versão do `gcovr` será exibida no terminal.



## Projeto de Cobertura de Código com `gcovr`

Este projeto demonstra como organizar arquivos de código em C, compilar com suporte a cobertura de código, rodar testes e gerar relatórios de cobertura utilizando o `gcovr`.

### Estrutura de Diretórios

O projeto é organizado da seguinte forma:

```bash
Diretorio/
│── src/         (Código-fonte)
│   ├── programa.c
│   ├── programa.h
│   ├── main.c
│   ├── programa_test.c
│── build/       (Arquivos compilados)
│   ├── programa.o
│   ├── main.o
│   ├── programa_test.o
│── bin/         (Executáveis)
│   ├── programa
│   ├── programa_test
│── coverage/    (Relatórios de cobertura)
│   ├── cobertura.html
│   ├── cobertura.css
│   ├── *.gcda
│   ├── *.gcno
```

### Passo a Passo

#### 1. Criar as Pastas

Primeiro, crie a estrutura de diretórios necessária para organizar o projeto:

```bash
mkdir -p src build bin coverage
```

#### 2. Mover os Arquivos-Fonte

Depois de criar as pastas, a segunda linha de comando move os arquivos-fonte existentes para a pasta src/. O comando mv é usado para mover arquivos de um diretório para outro.

```bash
mv programa.c programa.h main.c programa_test.c src/
```

-   **programa.c:** Arquivo que contém a implementação do código principal do programa.
-   **programa.h:** Arquivo de cabeçalho associado ao código-fonte do programa, contendo declarações e definições de funções e variáveis.
-   **main.c:** Arquivo que contém a função principal (main) do programa, onde o programa é inicializado e executado.
-   **programa_test.c:** Arquivo que contém os testes do programa, usados para verificar seu comportamento e funcionalidade.

#### 3. Compilar com Arquivos Organizados

Compile os arquivos-fonte com a opção --coverage para gerar os arquivos necessários para o cálculo da cobertura de código:

```bash
g++ --coverage -c src/programa.c -o build/programa.o
```
```bash
g++ --coverage -c src/main.c -o build/main.o
```
```bash
g++ --coverage -c src/programa_test.c -o build/programa_test.o
```

#### 4. Criar os Executáveis

Após compilar os arquivos-fonte, crie os executáveis:

```bash
g++ --coverage -o bin/programa build/main.o build/programa.o
```
```bash
g++ --coverage -o bin/programa_test build/programa_test.o build/programa.o
```

#### 5. Rodar os Testes

Execute os testes com o comando abaixo:

```bash
bin/programa
```
```bash
bin/programa_test
```

#### 6. Gerar o Relatório de Cobertura

Por fim, gere o relatório de cobertura em formato HTML utilizando o gcovr:

```bash
gcovr --branches --html --html-details -o coverage/cobertura.html
```

## Conclusão
Com os passos apresentados, você conseguiu estruturar seu projeto de forma eficiente, adicionando cobertura de código, compilando o programa com o suporte necessário, executando os testes e gerando relatórios detalhados. Esse processo não só melhora a qualidade do seu código, mas também proporciona maior confiança nos testes realizados, permitindo identificar facilmente as partes do código que ainda precisam de atenção.

Organizar o projeto dessa forma facilita o gerenciamento dos diferentes arquivos e torna o processo de monitoramento da cobertura de código mais fluido, especialmente em projetos maiores. O uso do gcovr traz uma abordagem simples e eficaz para integrar essa análise no seu fluxo de trabalho, seja em desenvolvimento local ou em pipelines de integração contínua.
