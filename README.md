# Laboratoire 1 du cours Architecture des logiciels
Un logiciel de lecture vidéo simple

Par Jérémy Bouchard et Émile Bélanger

Ce logiciel simple permet la lecture d'une vidéo entrée dans le code source du
programme et de contrôler la lecture de la vidéo au moyen des touches du
clavier.

# Comment exécuter le programme?

Ouvrir le fichier 'Laboratoire1.sln', exécuter l'application sans débogage
(ctrl+F5). 

# Quelles sont les fonctionnalités du programme?

- Lecture et arrêt de la vidéo au moyen de la touche 'P'
- Avance rapide de la vidéo au moyen de la touche 'A'
- Retour au début de la vidéo au moyen de la touche 'R'
- Arrêt du programme (et de la vidéo) au moyen de la touche 'Q'
- Aide au moyen de la touche 'H'

# Détail de l'implémentation de chacune des fonctions

**Lecture**

L'appui de la touche 'P', dépendemment de la situation, fera jouer ou arrêter
la vidéo. La fonction teste, selon le cas, si l'état de la vidéo est sur 'Play'
ou sur 'Pause' et est implémentée en utilisant les fonctions de contrôle de
transport de base incluses dans DirectShow.

**Avance rapide**

L'appui de la touche 'A' fera avancer la vidéo à une vitesse de 2x, un second
appui de la touche ramènera la vitesse de la vidéo à 1x. La fonction est
implémentée en utilisant les fonctionnalités de contrôle de vitesse de
DirectShow.

**Reprendre la vidéo du début**

L'appui de la touche 'R' fera reprendre la vidéo à son tout début.

**Arrêter la vidéo**

L'appui de la touche 'Q' fermera le programme et arrêtera par le fait même la
vidéo.

**Aide**

Une rubrique d'aide est affichée à l'appui de la touche 'H' et automatiquement
à l'ouverture du programme.

# Comment le programme peut-il lire les entrées du clavier continuellement?

Une boucle infinie attend la lecture d'une instruction du clavier, si une
instruction est entrée, la fonction correspondante à cette instruction est
appelée, sinon, 1ms de la vidéo est lue.

# Comment lire la vidéo locale sur l'ordinateur

Il est nécessaire de spécifier le dossier et le nom du fichier vidéo à lire à
la dix-huitième ligne du fichier 'main.cpp'.

# Comment les composantes du programme intéragissent-elles entre elle?

Les composantes sont reliées entre elle telles que représentées par ce
schéma d'architecture d'interface (SAI) :

![alt text](https://i.imgur.com/k5cYgcv.png)
