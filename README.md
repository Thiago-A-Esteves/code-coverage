# Gcovr - Ferramenta de Cobertura de Código

O `gcovr` é uma ferramenta de linha de comando que gera relatórios de cobertura de código a partir dos arquivos de cobertura produzidos pela ferramenta gcov, que é parte do GCC (GNU Compiler Collection). Ele é projetado para ser uma solução simples e eficiente para acompanhar a cobertura de código de projetos em C e C++. Com o uso do `gcovr`, os desenvolvedores podem obter insights detalhados sobre a execução do código durante os testes, ajudando a identificar áreas não cobertas, aprimorar a qualidade do código e aumentar a confiança nos testes realizados.

# Funcionalidades Principais:
`Geração de Relatórios:` O gcovr suporta diferentes formatos de saída para os relatórios de cobertura de código:

`Texto:` Resumo simples da cobertura de código.

`HTML:` Relatórios visualmente amigáveis e interativos.

`XML:` Útil para integração com sistemas de CI/CD, como Jenkins, GitLab CI, entre outros.

`Integração com Ferramentas de CI/CD:` A saída XML pode ser integrada facilmente em pipelines de CI/CD, permitindo que a cobertura do código seja monitorada automaticamente durante o processo de integração contínua.

`Suporte a Múltiplos Arquivos e Diretórios:`O gcovr pode ser configurado para processar múltiplos diretórios e arquivos gerados durante a execução dos testes, o que o torna adequado para projetos grandes e complexos.

`Filtros de Cobertura:` Ele oferece opções para filtrar quais arquivos ou funções devem ser incluídos ou excluídos nos relatórios, permitindo que você se concentre nas áreas mais relevantes do código.

`Relatórios de Cobertura de Linha e de Função:` O gcovr pode gerar relatórios detalhados, tanto sobre a cobertura de linha quanto sobre a cobertura de função, proporcionando uma visão clara de quais partes do código estão sendo executadas pelos testes.

`Facilidade de Uso:` Como é uma ferramenta de linha de comando, o gcovr é bastante fácil de integrar em scripts de build e pipelines de automação, permitindo uma análise contínua da cobertura de código.

## Pontos Positivos do Gcovr:

`Simplicidade e Facilidade de Integração:` O gcovr é fácil de configurar e usar. Ele pode ser rapidamente integrado a sistemas de integração contínua e outros fluxos de trabalho automatizados, tornando-se ideal para projetos que requerem monitoramento contínuo da cobertura de código.

`Diversos Formatos de Relatório:` A capacidade de gerar relatórios em texto, HTML e XML permite que você adapte os relatórios às necessidades específicas do seu projeto, seja para leitura rápida ou para integração com outras ferramentas.

`Visibilidade no Processo de Testes:` O gcovr fornece uma visão clara de quais partes do código estão sendo cobertas pelos testes, ajudando a identificar áreas de risco que não estão sendo adequadamente testadas.

`Suporte à Análise de Cobertura em Projetos Grandes:` A capacidade de trabalhar com múltiplos diretórios e arquivos, bem como filtrar partes específicas do código, torna o gcovr útil para projetos grandes, onde você precisa de controle e detalhamento.

`Compatibilidade com o GCC:` Como o gcovr funciona com os arquivos de cobertura gerados pelo gcov, ele é totalmente compatível com projetos que já utilizam o GCC, o que torna a adoção mais simples em ambientes que já utilizam o GCC como compilador.

## Pontos Negativos do Gcovr:

`Dependência do GCC:` O gcovr depende do gcov para gerar arquivos de cobertura, o que significa que ele só funciona em projetos que utilizam o GCC como compilador. Isso pode ser uma limitação se você estiver usando outros compiladores, como Clang, embora o Clang tenha uma ferramenta similar.

`Relatórios Simples:` Embora o gcovr forneça relatórios úteis, eles podem ser bastante simples em comparação com outras ferramentas de cobertura mais sofisticadas, como o lcov ou soluções comerciais. Isso pode ser uma limitação se você precisar de análises mais detalhadas ou recursos avançados.

`Interação Limitada com Outras Ferramentas:` Embora o gcovr seja eficiente para gerar relatórios de cobertura, ele não possui tantas integrações nativas com ferramentas de terceiros, o que pode exigir configurações adicionais se você precisar de suporte para integrações mais complexas.

`Falta de Análises Avançadas:` Embora o gcovr ofereça informações valiosas sobre a cobertura, ele não tem tantas opções de personalização ou funcionalidades avançadas para análise de cobertura como algumas outras ferramentas mais especializadas. Ele pode não ser suficiente para projetos de grande escala que exigem uma análise mais detalhada do código.

`Problemas com Arquivos Grandes:` Em projetos muito grandes, o gcovr pode se tornar um pouco lento ou consumir muitos recursos ao processar grandes quantidades de dados de cobertura, especialmente se os relatórios forem complexos.



## Instalação

A instalação do `gcovr` pode ser feita de diferentes maneiras dependendo do sistema operacional.

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

## Verificando a Instalação
Após a instalação, verifique se o `gcovr` está instalado corretamente executando:
```bash
gcovr --version
```

Se a instalação foi bem-sucedida, a versão do `gcovr` será exibida no terminal.



# Projeto de Cobertura de Código com `gcovr`

Este projeto demonstra como organizar arquivos de código em C, compilar com suporte a cobertura de código, rodar testes e gerar relatórios de cobertura utilizando o `gcovr`.

## Estrutura de Diretórios

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

## Passo a Passo

### 1. Criar as Pastas

Primeiro, crie a estrutura de diretórios necessária para organizar o projeto:

```bash
mkdir -p src build bin coverage
```

### 2. Mover os Arquivos-Fonte

Depois de criar as pastas, a segunda linha de comando move os arquivos-fonte existentes para a pasta src/. O comando mv é usado para mover arquivos de um diretório para outro.

```bash
mv programa.c programa.h main.c programa_test.c src/
```

`programa.c:` Arquivo que contém a implementação do código principal do programa.

`programa.h:` Arquivo de cabeçalho associado ao código-fonte do programa, contendo declarações e definições de funções e variáveis.

`main.c:` Arquivo que contém a função principal (main) do programa, onde o programa é inicializado e executado.

`programa_test.c:` Arquivo que contém os testes do programa, usados para verificar seu comportamento e funcionalidade.

### 3. Compilar com Arquivos Organizados

Compile os arquivos-fonte com a opção --coverage para gerar os arquivos necessários para o cálculo da cobertura de código:

```bash
g++ --coverage -c src/programa.c -o build/programa.o
g++ --coverage -c src/main.c -o build/main.o
g++ --coverage -c src/programa_test.c -o build/programa_test.o
```

### 4. Criar os Executáveis

Após compilar os arquivos-fonte, crie os executáveis:

```bash
g++ --coverage -o bin/programa build/main.o build/programa.o
g++ --coverage -o bin/programa_test build/programa_test.o build/programa.o
```

### 5. Rodar os Testes

Execute os testes com o comando abaixo:

```bash
bin/programa
bin/programa_test
```

### 6. Gerar o Relatório de Cobertura

Por fim, gere o relatório de cobertura em formato HTML utilizando o gcovr:

```bash
gcovr --branches --html --html-details -o coverage/cobertura.html
```

# Conclusão
Com esses passos, você organizou seu projeto de maneira eficiente, compilou o código com suporte à cobertura, executou os testes e gerou um relatório de cobertura. A estrutura de pastas facilita o gerenciamento do código-fonte, dos arquivos compilados, dos executáveis e dos relatórios de cobertura.