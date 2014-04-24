Player busts
============

```
$ ./a.out 
Hand for dealer
7 of hearts

Hand for player
6 of clubs
7 of clubs
 total: 13

(H)it or (S)tay? 
H
You have choen hit, dealing another card.
BUST!
Hand for player
6 of clubs
7 of clubs
Queen of hearts
 total: 23

Dealer wins.
Final Hands
Hand for dealer
7 of hearts
8 of hearts
 total: 15

Hand for player
6 of clubs
7 of clubs
Queen of hearts
 total: 23
```

Dealer wins
===========

```
$ ./a.out 
Hand for dealer
4 of clubs

Hand for player
3 of spades
4 of spades
 total: 7

(H)it or (S)tay? 
H
You have choen hit, dealing another card.
Hand for player
3 of spades
4 of spades
10 of clubs
 total: 17

(H)it or (S)tay? 
S
You have chosen to stay, here is your final hand.
Hand for player
3 of spades
4 of spades
10 of clubs
 total: 17

Hand for dealer
4 of clubs
5 of diamonds
 total: 9

Dealer must hit.
Hand for dealer
4 of clubs
5 of diamonds
King of diamonds
 total: 19

Dealer wins.
Final Hands
Hand for dealer
4 of clubs
5 of diamonds
King of diamonds
 total: 19

Hand for player
3 of spades
4 of spades
10 of clubs
 total: 17
```

Player wins
===========

```
$ ./a.out 
Hand for dealer
5 of diamonds

Hand for player
King of spades
9 of diamonds
 total: 19

(H)it or (S)tay? 
s
Please enter 'H' for Hit or 'S' for Stay: 
S
You have chosen to stay, here is your final hand.
Hand for player
King of spades
9 of diamonds
 total: 19

Hand for dealer
5 of diamonds
3 of hearts
 total: 8

Dealer must hit.
Hand for dealer
5 of diamonds
3 of hearts
10 of spades
 total: 18

You win!
Final Hands
Hand for dealer
5 of diamonds
3 of hearts
10 of spades
 total: 18

Hand for player
King of spades
9 of diamonds
 total: 19
```

Invalid Input
=============

```
$ ./a.out 
Hand for dealer
Ace of diamonds

Hand for player
2 of hearts
6 of diamonds
 total: 8

(H)it or (S)tay? 
hit
Please enter 'H' for Hit or 'S' for Stay: 
stay
Please enter 'H' for Hit or 'S' for Stay: 
h
Please enter 'H' for Hit or 'S' for Stay: 
H
You have choen hit, dealing another card.
Hand for player
2 of hearts
6 of diamonds
5 of hearts
 total: 13

(H)it or (S)tay? 
H
You have choen hit, dealing another card.
BUST!
Hand for player
2 of hearts
6 of diamonds
5 of hearts
King of hearts
 total: 23

Dealer wins.
Final Hands
Hand for dealer
Ace of diamonds
2 of diamonds
 total: 13

Hand for player
2 of hearts
6 of diamonds
5 of hearts
King of hearts
 total: 23
```

Dealer Blackjack
================

```
$ ./a.out 
Hand for dealer
Ace of diamonds

Hand for player
8 of clubs
Jack of diamonds
 total: 18

BLACKJACK - Dealer wins with blackjack.
Final Hands
Hand for dealer
Ace of diamonds
Queen of spades
 total: 21

Hand for player
8 of clubs
Jack of diamonds
 total: 18
```

Player Blackjack
================

```
$ ./a.out 
Hand for dealer
10 of hearts

Hand for player
Ace of hearts
10 of diamonds
 total: 21

BLACKJACK! You win!
Final Hands
Hand for dealer
10 of hearts
2 of clubs
 total: 12

Hand for player
Ace of hearts
10 of diamonds
 total: 21
```
