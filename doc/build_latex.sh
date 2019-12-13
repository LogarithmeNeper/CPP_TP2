#!/bin/bash
pdflatex --shell-escape -synctex=1 -interaction=nonstopmode $(dirname "$0")/"compte_rendu.tex"
