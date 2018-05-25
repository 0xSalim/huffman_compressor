.PHONY: clean,documentation,rapport

SRCDIR=src
LIBDIR=lib
BINDIR=bin
BINTESTDIRTAD=testTAD
SRCTESTDIRTAD=testTAD
BINTESTDIRHUF=testHuffman
DOCDIR=doc
SRCTESTDIRHUF=testHuffman
INCLUDEDIR=include
TADDIR=TAD
HUFFMANDIR=Huffman
CC = gcc
AR = ar
LDLIBS := -lm
CFLAGS=-Wall -pedantic -g -pg -std=c99 -fshort-enums
LDFLAGS= -lhuffman -ltad -Llib
EXEC= huffman

.PHONY : doc tests clean
 
all : $(EXEC)


mkdir : 
	mkdir -p doc bin lib 

doc  : $(DOCDIR)/html/index.html

$(EXEC) : $(BINDIR)/$(EXEC) $(BINDIR)/$(BINTESTDIRTAD)/TU_Octet $(BINDIR)/$(BINTESTDIRTAD)/TU_ADH $(BINDIR)/$(BINTESTDIRTAD)/TU_TableDeCodage $(BINDIR)/$(BINTESTDIRTAD)/TU_CodeBinaire $(BINDIR)/$(BINTESTDIRTAD)/TU_fileDePriorite  $(BINDIR)/$(BINTESTDIRTAD)/TU_Statistiques $(BINDIR)/$(BINTESTDIRTAD)/TU_ListeChainee

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libtad.a $(LIBDIR)/libhuffman.a
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(CFLAGS) $(LDLIBS)

$(BINDIR)/$(BINTESTDIRTAD)/TU% : $(SRCDIR)/$(SRCTESTDIRTAD)/TU%.o $(LIBDIR)/libtad.a
	$(CC) -o $@ $< -ltad -lcunit -Llib $(CFLAGS) $(LDLIBS)

$(BINDIR)/$(BINTESTDIRHUF)/TU% : $(SRCDIR)/$(SRCTESTDIRHUFF)/TU%.o $(LIBDIR)/libhuffman.a $(LIBDIR)/libtad.a
	$(CC) -o $@ $< -lhuffman -lcunit -ltad -Llib $(CFLAGS) $(LDLIBS)

$(LIBDIR)/libtad.a : $(SRCDIR)/$(TADDIR)/Octet.o $(SRCDIR)/$(TADDIR)/CodeBinaire.o $(SRCDIR)/$(TADDIR)/Statistiques.o $(SRCDIR)/$(TADDIR)/fichierBinaire.o $(SRCDIR)/$(TADDIR)/tableDeCodage.o $(SRCDIR)/$(TADDIR)/arbreDeHuffman.o $(SRCDIR)/$(TADDIR)/FileDePriorite.o $(SRCDIR)/$(TADDIR)/ListeChainee.o $(SRCDIR)/$(TADDIR)/entier_allocation_dynamique.o $(SRCDIR)/$(TADDIR)/arbre_allocation_dynamique.o $(SRCDIR)/$(TADDIR)/bit_allocation_dynamique.o $(SRCDIR)/$(TADDIR)/bit.o $(SRCDIR)/$(TADDIR)/S_donneeNoeud_AD.o
	$(AR) -q $@ $^

$(LIBDIR)/libhuffman.a : $(SRCDIR)/$(HUFFMANDIR)/compresser.o $(SRCDIR)/$(HUFFMANDIR)/decoder.o $(SRCDIR)/$(HUFFMANDIR)/decompresser.o $(SRCDIR)/$(HUFFMANDIR)/ecrireCodeBinaire.o  $(SRCDIR)/$(HUFFMANDIR)/ecrireEnTete.o $(SRCDIR)/$(HUFFMANDIR)/estCompresse.o $(SRCDIR)/$(HUFFMANDIR)/estCompressible.o $(SRCDIR)/$(HUFFMANDIR)/genererADH.o $(SRCDIR)/$(HUFFMANDIR)/genererFDP.o $(SRCDIR)/$(HUFFMANDIR)/genererStats.o $(SRCDIR)/$(HUFFMANDIR)/genererTDCaPartirDeADH.o $(SRCDIR)/$(HUFFMANDIR)/genererTDCaPartirDeStats.o $(SRCDIR)/$(HUFFMANDIR)/recupererEnTete.o
	$(AR) -q $@ $^

$(SRCDIR)/main.o : $(SRCDIR)/main.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS) -I$(INCLUDEDIR)

$(SRCDIR)/$(TADDIR)/%.o : $(SRCDIR)/$(TADDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR) -ltad 


$(SRCDIR)/$(HUFFMANDIR)/%.o : $(SRCDIR)/$(HUFFMANDIR)/%.c
	$(CC) -o $@ -c $< -I$(INCLUDEDIR) $(CFLAGS) -ltad

$(SRCDIR)/$(SRCTESTDIRTAD)/%.o : $(SRCDIR)/$(SRCTESTDIRTAD)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDLIBS) -I$(INCLUDEDIR) 

$(SRCDIR)/$(SRCTESTDIRHUF)/%.o : $(SRCDIR)/$(SRCTESTDIRHUF)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDLIBS) -I$(INCLUDEDIR)

doc :
$(DOCDIR)/html/index.html :
	cd doc && doxygen

clean :
	rm -rf $(BINDIR)/$(EXEC)
	rm -rf $(LIBDIR)/*.a
	rm -rf $(SRCDIR)/$(TADDIR)/*.o
	rm -rf $(SRCDIR)/*.o
	rm -rf $(SRCDIR)/$(HUFFMANDIR)/*.o
	rm -rf $(BINDIR)/$(BINTESTDIRTAD)/TU*
	rm -rf $(SRCDIR)/$(SRCTESTDIRTAD)/*.o
	rm -rf $(BINDIR)/$(BINTESTDIRHUF)/TU*
	rm -rf $(SRCDIR)/$(SRCTESTDIRHUF)/*.o
	rm -rf $(DOCDIR)/html
	rm -rf $(DOCDIR)/latex
	rm -rf gmon.out

