# Résultats d'analyse - TP1 Système routier

## Tableau des résultats

| Configuration | PRIORITY_LIGHT | FIXED_LIGHT | FOUR_WAY_STOP |
| :-----------: | :------------: | :---------: | :-----------: |
|     EVEN      |       29       |     29      |      59       |
|    ONEWAY     |       46       |     49      |      59       |
|  UNBALANCED   |       34       |     36      |      59       |

_Temps d'attente moyen en tours par véhicule (120 véhicules total)_

## Analyse

### Meilleure algorithme par configuration

- **EVEN** : PRIORITY et FIXED sont égaux puisqu'ils font
- **ONEWAY** : PRIORITY est meilleure puisqu'il reste vert inutilement moin longtemps que FIXED lorsqu'une file est vide
- **UNBALANCED** : PRIORITY est meilleure puisqu'il reste vert inutilement moin longtemps que FIXED lorsqu'une file est vide

### Observations générales

FOUR_WAY_STOP n'a pas pas d'avantage puisqu'il laisse passer une seul voiture à la fois.
FIXED_LIGHT est constant et cause des tours inutile lorsque qu'il y a des files vides.
PRIORITY_LIGHT est le meilleure car il va chercher de l'éfficaté en ne restant pas vert inutilement dans des file vide.

### Complexité algorithmique

Je sais pas quoi répondre tbh

### Conclusion

On peut dire que PRIORITY_LIGHT est meilleure dans tous les cas. Même si FIXED_LIGHT est égal lors d'une situation EVEN, il n'y a pas de raison de l'utiliser si l'autre est meilleure dans les autres cas.
