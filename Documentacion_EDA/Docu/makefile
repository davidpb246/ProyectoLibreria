OBJS = docu.tex
CC = pdflatex
TARGET = docu
$(TARGET) : $(OBJS)
	$(CC) $(OBJS)
clean:
	rm -f docu.log *.aux *.pdf $(TARGET)
