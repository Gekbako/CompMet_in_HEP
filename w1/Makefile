MAIN = main

OUTDIR = .


LATEXMK = latexmk
LATEXMK_OPTS = -synctex=1 -interaction=nonstopmode -file-line-error -pdf -shell-escape -output-directory=$(OUTDIR)
MP = mpost


all: $(MAIN).pdf


$(MAIN).pdf: $(MAIN).tex
	$(LATEXMK) $(LATEXMK_OPTS) $(MAIN)


%.mp:
	$(MP) $<


cleanall: clean
	rm -f $(MAIN).pdf

.PHONY: all clean cleanall