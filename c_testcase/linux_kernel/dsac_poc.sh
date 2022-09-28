#!/bin/bash

# since cases are too simple, use -noinline to keep all function calls in position.

# compile rule
xvsa -c -xfa -noinline dsac_rule.cxx -o dsac_rule.o $*

# compile cases & link with rule to check
xvsa -c -xfa -noinline mv_udc_core.c -o mv_udc_core.o $*
xvsa -xfa -noinline mv_udc_core.o dsac_rule.o $*

xvsa -c -xfa -noinline if_vte.c -o if_vte.o $*
xvsa -xfa -noinline if_vte.o dsac_rule.o $*
