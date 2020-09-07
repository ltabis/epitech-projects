#!/bin/bash

read -p "\x1b[34mMessage de mise à jour : \x1b[0m" message

read -p "\x1b[34mbranche : \x1b[34m" branche

git add --all
git commit -m "$message"
git push origin $branche
