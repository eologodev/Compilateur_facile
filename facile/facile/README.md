# Projet Compilateur FLEX/BISON — Langage `facile`

Licence Informatique 3ème année — Université de La Rochelle


---

## Prérequis (Linux)

```bash
sudo apt-get install flex bison cmake libglib2.0-dev mono-complete
```

- **flex** : analyseur lexical 
- **bison** : analyseur syntaxique
- **cmake** : système de build
- **libglib2.0-dev** : structures de données (arbres n-aires, tables de hachage)
- **mono-complete** : compilateur (`mcs`), assembleur (`ilasm`), exécuteur (`mono`) C#

---

## Structure du projet

```
facile/
├── CMakeLists.txt      — configuration du build
├── facile.lex          — analyseur lexical (flex)
├── facile.y            — analyseur syntaxique + génération de code (bison)
├── test_base.facile    — test lecture/affectation/arithmétique
├── test_if.facile      — test if/elseif/else (exercices 4-6)
├── test_while.facile   — test while/break/continue (exercices 7-9)
└── pgcd.facile         — PGCD par algorithme d'Euclide (exercice 10)
```

---

## Compilation du compilateur

```bash
mkdir build
cd build

# Mode Debug (affiche les tokens reconnus)
cmake -DCMAKE_BUILD_TYPE=Debug ..
make

# Mode Release (silencieux)
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

---

## Utilisation

```bash
# Compiler un programme .facile → génère un fichier .il
./facile ../pgcd.facile

# Assembler le .il en .exe (assembleur CIL de Mono)
ilasm pgcd.il

# Exécuter
mono pgcd.exe
```

---

## Exercices réalisés

| # | Exercice |
|---|----------|
| 1 | Ajout des mots-clés |
| 2 | Ajout des ponctuations |
| 3 | Ajout des nombres |
| 4 | Gestion des tests simples (if sans else/elseif) |
| 5 | Gestion des tests complexes (if avec else/elseif) |
| 6 | Gestion des tests imbriqués |
| 7 | Gestion des boucles simples (while sans break/continue) |
| 8 | Gestion des boucles complexes (break/continue) |
| 9 | Gestion des boucles imbriquées |
| 10 | Le PGCD |

---

## Améliorations apportées (au-delà du sujet)

### 1. Commentaires sur une ligne (`//`)
Le lexer ignore tout ce qui suit `//` jusqu'à la fin de la ligne.
```
// ceci est un commentaire
read a;   // lecture de a
```

### 2. `add_flex_bison_dependency` dans CMakeLists
Garantit que `facile.y.h` est généré **avant** la compilation de `facile.lex.c`,
évitant les erreurs de build en parallèle (`make -j`).

### 3. `strdup` sur `yytext` dans le lexer
`yytext` est un buffer volatile écrasé au prochain token.
La valeur sémantique `yylval.string` reçoit une copie (`strdup`) pour ne pas
corrompre l'arbre syntaxique.

### 4. Gestion sémantique de `break` et `continue` avec pile de boucles
Un tableau de labels (`loop_start_labels`, `loop_end_labels`) simule une pile.
Quand on entre dans un `while`, les labels de début et de fin sont empilés.
`break` saute au label de fin, `continue` au label de début.
Cela supporte les **boucles imbriquées** à profondeur arbitraire.

### 5. Génération CIL complète des booléens
Tous les opérateurs de comparaison (`=`, `#`, `<`, `>`, `<=`, `>=`) et
logiques (`and`, `or`, `not`, `true`, `false`) sont traduits en instructions
CIL natives (`ceq`, `cgt`, `clt`, `and`, `or`).

### 6. Validation du nom de module
Le `main` vérifie que le nom de base du fichier `.facile` est un identifiant
CIL valide (commence par une lettre ou `_`, ne contient que des alphanumériques
et `_`). Un message d'erreur clair est affiché sinon.

### 7. `%option nounput noinput`
Supprime les warnings GCC sur les fonctions générées par flex mais non utilisées.

---

## Exemple de session complète (PGCD de 48 et 18)

```bash
$ ./facile ../pgcd.facile
$ ilasm pgcd.il
Assembling 'pgcd.il' , no listing file, to exe --> 'pgcd.exe'
Operation completed successfully
$ mono pgcd.exe
48
18
6
```

---

## Notes sur la grammaire CIL générée

| Opération facile | Instructions CIL |
|---|---|
| `a := expr;` | `<expr>` puis `stloc N` |
| `read a;` | `call ReadLine()` -> `call Parse()` -> `stloc N` |
| `print expr;` | `<expr>` puis `call WriteLine(int32)` |
| `a + b` | `ldloc a`, `ldloc b`, `add` |
| `a >= b` | `ldloc a`, `ldloc b`, `clt`, `ldc.i4 0`, `ceq` |
| `not b` | `<b>`, `ldc.i4 0`, `ceq` |
| `if cond then ... endif` | `<cond>`, `brfalse L_NEXT`, `<then>`, `br L_END` |
| `while cond do ... endwhile` | `L_START:`, `<cond>`, `brfalse L_END`, `<body>`, `br L_START` |
