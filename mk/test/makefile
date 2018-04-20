### makefile for this project ###

OUTPUT_DIR=out
SRC=src
INC=inc

ifneq ($(OUTPUT_DIR), $(wildcard $(OUTPUT_DIR)))
#$(shell echo "${OUTPUT_DIR} doesn't exist,create it" )
$(shell mkdir ${OUTPUT_DIR} )
endif


${OUTPUT_DIR}/app:${OUTPUT_DIR}/main.o
	@echo "make $(@)"
	gcc -o $(@) $(<)
${OUTPUT_DIR}/main.o:${SRC}/main.c
	@echo "make $(@)"
	gcc -o $(@) -c $(<) 

.PHONY:clean
clean:
	@echo "clean.."
	-rm ${OUTPUT_DIR}/*.o ${OUTPUT_DIR}/app
