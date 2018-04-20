### makefile for this project ###

OUTPUT_DIR=out
OBJS_DIR=${OUTPUT_DIR}/obj
SRC=src
INC=inc

# make out dir if not exists
ifneq ($(OUTPUT_DIR), $(wildcard $(OUTPUT_DIR)))
#$(shell echo "${OUTPUT_DIR} doesn't exist,create it" )
$(shell mkdir ${OUTPUT_DIR} )
endif

ifneq ($(OBJS_DIR),$(wildcard $(OBJS_DIR)))
$(shell mkdir ${OBJS_DIR} )
endif

# make out/obj dir if not exists
objs=${OBJS_DIR}/main.o ${OBJS_DIR}/utils.o

${OUTPUT_DIR}/app:${objs}
	@echo "make $(@)"
	gcc -o $(@) $(^)

${OBJS_DIR}/%.o:${SRC}/%.c
	@echo "make $(@)"
	gcc -o $(@) -c $(<) -I ${INC}

.PHONY:clean
clean:
	@echo "clean.."
	-rm -rf ${OBJS_DIR} ${OUTPUT_DIR}/app
