#Git Class
![Git](https://upload.wikimedia.org/wikipedia/commons/e/e0/Git-logo.svg)
O objetivo dessas aulas é apresentar e exercitar alguns comandos intermediários do Git, assim como ensinar a identificar e melhorar os commits de cada participante. Dessa forma, construimos projetos mais organizados ao aumentarmos a granularidade dos ajustes submetidos ao controle de versão.

Acesso rápido:
- [Aula 1 - `git reset` e `git add`](#Aula1)
- [Aula 2 - `git rebase`](#Aula2)
- [Exercício Extra](#Extra)

***

#<a name="Aula1"></a>Aula 1 - Qual o contrário do `git commit --amend`? Conheça o `git reset HEAD~`!
Nessa aula conheceremos e aprenderemos a utilizar o comando `git reset` para reverter o último commit, possibilitando a alteração dos arquivos a serem commitados.
- Branch de trabalho: [reset-and-patch](https://github.com/spidey/git-class/tree/reset-and-patch)
- [Utilizando o `git reset` para reverter o último commit](https://git-scm.com/book/pt-br/v1/Ferramentas-do-Git-Reescrevendo-o-Hist%C3%B3rico#Dividindo-um-Commit)
- [Manual do `git reset`](https://git-scm.com/docs/git-reset)

    ##Aula 1, Parte 2 - Que tal commitar apenas um pedaço de um arquivo? `git add -i` e `-p` ao resgate!
Aqui conheceremos o modo interativo do comando `git add`, que nos possibilita ter um controle maior sobre o que será commitado, o que está adicionado, o que ainda não está sendo versionado.
- [Utilizando o `git add` interativo](https://git-scm.com/book/pt-br/v1/Ferramentas-do-Git-%C3%81rea-de-Sele%C3%A7%C3%A3o-Interativa)
- [Manual do `git add`](https://git-scm.com/docs/git-add)

Como exercício, identifique um commit seu no POSWEB/POSNET/porting que poderia ser dividido em um ou mais commits independentes. Crie um branch local, faça o checkout dele, resete o último commit e refaça-o com mais granularidade, utilizando o `git add` interativo. Revise seu trabalho utilizando o `gitk`.

***

#<a name="Aula2"></a>Aula 2 - `git rebase -i`: modo interativo para ter ainda mais controle sobre seus branches
Utilizaremos a ferramenta de `rebase` do git para evitar conflitos quando formos entregar um feature branch. Aprenderemos o modo interativo, que nos permite reordenar, remover, editar e até juntar commits, criando commits mais relevantes, entregas com granularidade na medida certa.
- Branch de trabalho: [styling](https://github.com/spidey/git-class/tree/styling)
- [Utilizando o `git rebase` para editar o histórico](https://git-scm.com/book/pt-br/v1/Ferramentas-do-Git-Reescrevendo-o-Hist%C3%B3rico)
- [Manual do `git rebase`](https://git-scm.com/docs/git-rebase)

De quais formas é possível atualizar um feature branch local em relação ao seu branch de origem (`develop` no caso de uma nova funcionalidade)? Quais as vantagens e desvantagens de cada uma dessas formas?
Como exercício, identifique um feature branch do POSWEB que recebeu um merge do branch de origem como forma de evitar muitos conflitos no momento de entrega, e refaça o sincronismo utilizando o `git rebase`. Utilize o `git reset` e `git rebase` para te auxiliar nesta tarefa. Não se esqueça de criar branches locais de backup, para não perder as referências originais. Isto é, crie um branch de backup no último commit antes do merge de entrega do feature branch e um antes do commit de merge de atualização do branch principal. Após o trabalho concluído, faça o `git diff` e compare o resultado final, identificando se existem diferenças entre as duas abordagens de atualização do feature branch.

***

#<a name="Extra"></a>Exercício Extra
Já pensou em mergear uma reestruturação das pastas de um projeto sem dor de cabeça? O Git é esperto o suficiente para identificar arquivos que foram apenas movidos, e consegue mergear modificações neles de forma transparente. Utilize o branch `folder-organization` para testar essa funcionalidade.
- Branch de trabalho: [folder-organization](https://github.com/spidey/git-class/tree/folder-organization)

Utilize as técnicas que já discutimos para finalizar a sua cópia do projeto, com todas as lições até agora discutidas. Utilize as duas abordagens de entrega do feature branch, `merge` e `rebase`. Aproveite e faça o `rebase` do `folder-organization` para o topo e também do topo para o `folder-organization`. Crie branches de backup para poder comparar o resultado das duas abordagens.