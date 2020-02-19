all: lilcave src.zip map.png
C = object.c misc.c noun.c location.c move.c openclose.c onoff.c reachable.c toggle.c inventory.c inventory2.c parser.c match.c combat.c consumables.c string_util.c main.c
H = object.h misc.h noun.h location.h move.h openclose.h onoff.h reachable.h toggle.h inventory.h inventory2.h parser.h match.h combat.h consumables.h string_util.h

success.txt: lilcave testscript.txt baseline.txt
	./test.sh
	mv -f transcript.txt $@

lilcave: $(C) $(H)
	gcc -Wall -Wextra -Wpedantic -Werror $(C) -o $@

object.h: object.awk object.txt
	awk -v pass=h -f object.awk object.txt > $@

object.c: object.awk object.txt
	awk -v pass=c1 -f object.awk object.txt > $@
	awk -v pass=c2 -f object.awk object.txt >> $@

map.png: map.gv
	dot -Tpng -o $@ $<

map.gv: map.awk object.txt
	awk -f map.awk object.txt > $@

src.zip: $(C) $(H) object.txt makefile testscript.txt baseline.txt
	zip -rq $@ $^

clean:
	$(RM) object.c object.h lilcave map.gv map.png transcript.txt success.txt

