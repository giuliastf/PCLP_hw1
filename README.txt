TEMA_1pclp
IMBREA GIULIA-STEFANIA 311CB

//task1
[1-2]includ bibliotecile <stdio.h> si < math.h>, ultima pentru ca ulterior o sa apelez functia pow

[4-15] functia bin
-aceasta functie transorma un nr de tip unsigned int(instructiunea) zecimal in binar cu ajutorul vectorului
bin[], considerand si numarul de biti in care dorim sa l interpretam (biti , la noi 32)
-urmareste logica impartirii repetate la 2.
ex 1234
daca exemplu 1234:2=617 r 0
     617:2=308 r 1
     308:2=154 r 0
     152:2=76 r 0
     76:2=38 r 0
     38:2=19 r 0
     19:2=9 r 1
     9:2=4 r 1
     4:2=2 r 0
     2:2=1 r 0
     1:2=0 r 1
-fiindca numerele zecimale in binar se construiesc prin rest citit de jos in sus am plecat cu for ul de la 
(biti-1)(ex:32-1=31) pana la 0 inclusiv

[19-21] DECLARATII
inst     -retine instructiune(de tip unsigned int)
inst_bin[32] -vector care retine valoarea in binar a instructiunii
N        -nr ul de operatii 
dim      -dimensiunea unui operand
tip_op[N]   - vector ce retine operatiile(*/+-)care trebuie efectuate(de tip char)
i        -contor
j        -contor

[22-23]citesc inst si il transform in binar(32 biti) in vectorul inst_bin;

[24-27] N
-acesta este reprezentat pe primi 3 biti din inst_bin de aceea for-ul lucreaza de la i=2 la 0 inclusiv
-transform din binar acesti trei biti in zecimal cu ajutorul functiei pow(baza=2, putere=2-i)
-valoarea in zecimal este retinuta de N initializat cu 1 deoarece la valoarea in zecimal a celor 3 biti 
trebuie adaugat 1(conform cerintei)
???????

[28-41] tip_op
-de la al 3-lea bit(considerand primul bit 0) incepe interpretarea operatiilor
-dimensiunea in biti a acestora depinde de N-ul calculat mai devreme
-fiindca o operatie este exprimata pe 2 biti, logic operatiile in total vor ocupa N*2 biti
-asadar contorul i din for va pleca de la 3, interpreteaza N*2 biti, deci citirea opeatiilor se va opri 
la i=N*2+2 

[42-45] dim
-procedez asemanator cum am facut cu N, doar ca se schimba nr ul de biti interpretati si pozitia lor in inst_bin
-asadar contorul 
-acesta este reprezentat de urmatorii 4 biti(dupa cei dedicati operatiilor ultimul fiind N*2+2) din inst_bin 
de aceea for-ul lucreaza de la N*2+2+4 pana la N*2+2

----------------------------------------------------------------------------------------------------------------------------

//task2
[1-44] aceleasi linii ca la task1 + mici adaugiri:
nr_opz - nr ul de operanzi 
nr     - nr citite de la tastatura din care ulterior vom obtine operanzii
opz    -vector ce retine operanzii obtinuti
nr_bin -vector care retine valoarea in binar a lui nr
k,x,y  -contori
o=0    -intermediar

[46-49] nr_opz
- nr_opz se obtine astfel: ((N+1)*Dim)/16, la care adaugam +1 in cazul in care rezultatul are vreun rest
- de aceea cu ajutorul unui if verific daca exista rest sau nu (cu %)si pliez forma lui nr_opz dupa caz

[51-67]crearea lui opz[]
-prin forul de la i=0 pana la i=nr_opz-1 citesc nr de la tastatura
-transform nr in binar cu functia bin
-cunosc faptul ca operanzii se interpreteaza cu ajutorul vectorului nr_bin din dim in dim
-ma folosesc de un y=1 pt a stii la a cata interpretare ma aflu si pana la ce element din nr_bin trebuie sa lucreaz

[68-80]
-initializez rez cu primul operand 
-in functie de ordinea operatiilor din tip_op execut calculele si aflu rezultatul

--------------------------------------------------------------------------------------------------------------------------------------
LA TASK2 IN INTERPRETAREA OPERANZILOR NU SE LUA CAZUL IN CARE dim!={1;2;4;8;16}
task3 va lua si acest punct in considerare

//task3
[1-50] aflare N, tip_op, dim, nr_opz explixate anterior

[52-61] crearea vectorului tot
-tot[nr_opz]  -memoreaza toate numerele citite si transformate in binar, adica fiecare nr_bin
-citesc toate nr de la tastatura nr
-le  transform pe rand in binar(nr_bin)
-ma folosesc de un y=1 ca sa stiu unde ma aflu in vectorul tot[]
-pt ca tot are elemente de la 0 la nr_opz*16, iar nr_bin de la 0 la 16 folosesc for ul de la linia 58

[62-72]opz
- avand toti nr_bin[] alipiti in vectorul tot, putem interpreta in ordine N+1 operanzi din dim in dim
- acesti operanzi ii memorez in opz[]

[74-87]rez
-este ca la task2

------------------------------------------------------------------------------------------------------------------------
//task4

[1-72]explicate anterior

[73-87] pas 1 : * si/ executate in ordine
-practic parcurg atat opz cat si tip_op (exemplu: 0 + 1 / 2 + 3 * 4 /5 )
-atunci cand dau de un * sau / execut operatia dinte opz(aflat pe aceeasi pozitie cu operatia) si opz+1 
-din 2 operanzi in urma operatiei imi ramane unul singur asa ca sCad N ul, (dimensiunea lui tip_op[] si lui opz[] scade)

[88-100]
-in tip_op mi au ramas doar + si -, imi ramane asadar sa efectuez operatiile in ordine 

