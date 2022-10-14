![logo wxWidgets](https://www.mysql.com/common/logos/logo-mysql-170x115.png "Logo wxWidgets")

# Instalação do Conector do MySql

De acordo com a [Wikipédia](https://pt.wikipedia.org/wiki/MySQL), "O MySQL é um sistema de gerenciamento de banco de dados, que utiliza a linguagem SQL como interface. É atualmente um dos sistemas de gerenciamento de bancos de dados mais populares da Oracle Corporation, com mais de 10 milhões de instalações pelo mundo."

O MySql possuí suporte e conexão para varias linguagens, nesse caso será exemplificado a instalação do conector para c++. 

## Instalação do Conector Linux 

> **important** Realize a [instalação do dontenv](/docs/install-dotenv.md) antes desse processo.

Instale as dependências:

``` bash
sudo apt update
sudo apt install libmysqlcppconn-dev 
```

Crie um arquivo .env na raiz do projeto e adicione as seguintes variaveis:
``` 
DB_HOST="tcp://link-do-mysql"
DB_USER="usuario"
DB_PASSWORD="senha"
DB_SCHEMA="database"
```

Verifique a instalação executando o teste:

``` bash
g++ tests/mysql-installation.cpp -o a.out -lmysqlcppconn -lmysqlcppconn-static -I/usr/local/include/laserpants/dotenv-0.9.2
./a.out
```