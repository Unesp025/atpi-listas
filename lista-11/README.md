## Exercicio 05 - Menu de lanchonete
/*
funcionamento:
    Primeiramente, o cardapio deve ser lido de um arquivo 
    'cardapio.txt'.
    O formato padronizado foi:
        Primeira linha: quantidade de linhas do arquivo;
        Linhas seguintes: <numero> <palavra>;
    O cardapio é lido e transformado em uma lista de palavras, 
    que é uma matriz de chars.
    A organização dessa lista de palavras é:
        Todo item cujo indice é par (ex: 0, 2, 4...) corresponde
        ao <numero> lido.
        Os itens em indices impares (ex: 1, 3, 5...) correspondem
        a <palavra>.
            Dessa forma, os itens sao guardados em pares-imaginários:
            ex: [['1'], ['c','a','f','e'], ['3'], ['m','i','s','t','o'], ...]
        indice:    0            1            2              3
    
    O usuário é exibido o cardapio e deve digitar o numero do item 
    listado na tela. Cada vez que digitar o numero, deve apertar ENTER
    para adicionar o item à lista de pedidos, que não quantifica cada
    item igual. 
    Pedidos é uma lista de palavras também, de tamanho inicial 10.
    Quando o usuário chega no 9º item, a lista é redimensionada para cima.

    Uma vez concluido o pedido, a lista de palavras 'pedido' obtida passa 
    por uma funcao que verifica a presenca de cada item do 'cardapio' em
    'pedido' e o quantifica. A quantidade de cada item e o nome do item
    sao então escritos no arquivo 'menu.txt', no formato já mencionado:
        <numero> <palavra>      ou seja... 
        <quantidade> <item> --> 3 misto

    Ao mesmo tempo, a quantidade de cada item é multiplicado por seu valor
    na tabela de precos e acontece a escrita no arquivo 'boleto.txt',
    seguindo o seguinte formato:
        <quantidade> x R$<preco> ..... <item>   ou seja...
        3            x R$5.00    ..... misto
    
    Portanto:
        entrada: 'cardapio.txt'
        saidas: 'menu.txt', 'boleto.txt'
teoria:
    Sabemos que uma palavra é um array de chars. Um array de
    chars pode ser representado por um ponteiro de char.
        Enderecos sequenciais na memoria armazenam, cada um,
        uma letra da palavra.
    Assim, um array de palavras é um array de array de chars. 
    Para fazer isso com ponteiros, alocamos um char **ptr.
        Para cada endereco sequencial alocado, aponta-se para o 
        array que contem uma palvra.
    Um ponteiro de ponteiro de char é uma LISTA de palavras.
    Uma matriz é uma LISTA de LISTAS.
    Uma matriz de ints é um PONTEIRO de PONTEIRO de int. 
    Logo uma matriz de chars é um PONTEIRO de PONTEIRO de PONTEIRO de chars.  
    
ideia:
    Para evitar uma matriz de palavras, que envolveria char ***ptr..., 
    vamos fazer:
        Uma lista de palavras : Ponteiro de ponteiro de char. 
        Cada elemento em posição par (0, 2, 4...) é o numero de itens.
        Cada elemento em posição impar (1, 3, 5...) é o item em si. 

problema:
    Ao usar ponteiros para obter os valores de item e quantidade do arquivo,
    a cada iteração, o valor naquele endereco muda.
    Por isso, ao fim da execução, todos os enderecos apontam para goiabada...
    (que é o ultimo item do menu)

    O certo seria passar direto o valor para o ponteiro, não o endereço
*/
