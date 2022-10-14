# Instalação do Dontev

Por motivos de segurança, chaves de bancos de dados, apis, criptografias, etc... Ficam armazenadas em arquivos de configuração. Para que fosse possível isso, utiliza-se a biblioteca dotenv-cpp de laserpants. 

[Acesse a licença: https://github.com/laserpants/dotenv-cpp/blob/master/LICENSE](https://github.com/laserpants/dotenv-cpp/blob/master/LICENSE)


## Instalação Linux 

Clone o código fonte:

``` bash
cd /tmp
git clone https://github.com/laserpants/dotenv-cpp.git 
```

Instale:

``` bash
cd dotenv-cpp/build
cmake ..
make
sudo make install
```

Verifique a instalação:

Crie uma variável chamada TESTE no .env e atribua um valor, execute e veja o valor em seu terminal:
``` bash
g++ tests/dotenv-installation.cpp -o a.out -I/usr/local/include/laserpants/dotenv-0.9.2
./a.out
```