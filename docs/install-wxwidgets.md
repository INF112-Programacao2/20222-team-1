![logo wxWidgets](https://www.wxwidgets.org/assets/img/header-logo.png "Logo wxWidgets")

# Instalação do wxWidgets

De acordo com seu [site](https://www.wxwidgets.org/), "wxWidgets é uma biblioteca C++ que permite aos desenvolvedores criar aplicativos para Windows, macOS, Linux e outras plataformas com uma única base de código. Ele tem ligações de linguagem populares para Python, Perl, Ruby e muitas outras linguagens e, ao contrário de outros kits de ferramentas multiplataforma, o wxWidgets dá aos aplicativos uma aparência verdadeiramente nativa porque usa a API nativa da plataforma em vez de emular a GUI. Também é extenso, gratuito, de código aberto e maduro."

[Acesse a licença: https://www.wxwidgets.org/about/licence/](https://www.wxwidgets.org/about/licence/)

Esse projeto foi construído utilizando sua versão 3.2.1

## Instalação Linux 

Instale as dependencias:

``` bash
sudo apt update
sudo apt install build-essential libgtk-4-dev 
```

Faça o download do código fonte e extraia:

``` bash
cd /tmp
wget https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.1/wxWidgets-3.2.1.tar.bz2 
tar -xvjf wxWidgets-3.2.1.tar.bz2
```

Configure o instalador:
``` bash
cd wxWidgets-3.2.1
./configure
```

Compile e instale utilizando cMake:
``` bash
make
sudo make install
```

> **Warning**
> Durante a execução da pré compilação, podem ocorrer erros de ausência de dependências. As instale e repita o passo.


Verifique a instalação:

``` bash
wx-config --version
```

Você também pode rodar o [código de exemplo](/tests/wxwidgets-installation.cpp), se tudo ocorrer bem, você verá uma janela padrão ao executar o compilado. 

```bash
g++ tests/wxwidgets-installation.cpp `wx-config --cppflags --libs` -o test_wxwidgets.out
./test_wxwidgets.out
```