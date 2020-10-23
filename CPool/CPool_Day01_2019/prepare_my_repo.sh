#!/bin/bash
blih -u dimitry.decou@epitech.eu repository create $1 ;
blih -u dimitry.decou@epitech.eu repository setacl $1 ramassage-tek r ;
blih -u dimitry.decou@epitech.eu repository getacl $1 ;



