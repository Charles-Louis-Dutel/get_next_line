# Get Next Line — École 42

Projet développé en **C** dans le cadre du cursus de l'école 42.

L'objectif est d'implémenter une fonction `get_next_line()` permettant de lire un fichier ou une entrée ligne par ligne, à partir d'un descripteur de fichier (*file descriptor*).

Ce projet permet d'approfondir la gestion de la mémoire, la lecture de fichiers et la manipulation des buffers.

## Fonctionnalités

- Lecture progressive d'un fichier, ligne par ligne.
- Utilisation de l'appel système `read()`.
- Gestion d'un buffer de taille configurable avec `BUFFER_SIZE`.
- Conservation des données non consommées entre deux appels.
- Gestion de la fin de fichier et des erreurs de lecture.
- **Partie bonus :** gestion de plusieurs descripteurs de fichiers simultanément.

## Compétences mises en œuvre

- Programmation en C
- Manipulation des descripteurs de fichiers
- Gestion dynamique de la mémoire
- Pointeurs et listes chaînées
- Variables statiques
- Gestion des buffers

## Auteur

Charles-Louis Dutel — [GitHub](https://github.com/Charles-Louis-Dutel)
