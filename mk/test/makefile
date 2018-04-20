### makefile for this project ###
#CUR_DIR      =  $(shell pwd)
CUR_DIR      =  .
 
SRC         =  $(CUR_DIR)/src
INC         =  $(CUR_DIR)/inc
OUTPUT_DIR  =  ${CUR_DIR}/out
OBJS_DIR    =  ${OUTPUT_DIR}/obj

CFLAGS      =  -I $(INC) -Wall -g -std=c99

# make out dir if not exists
ifneq ($(OUTPUT_DIR), $(wildcard $(OUTPUT_DIR)))
#$(shell echo "${OUTPUT_DIR} doesn't exist,create it" )
$(shell mkdir ${OUTPUT_DIR} )
endif

# make out/obj dir if not exists
ifneq ($(OBJS_DIR),$(wildcard $(OBJS_DIR)))
$(shell mkdir ${OBJS_DIR} )
endif

objs=${OBJS_DIR}/main.o ${OBJS_DIR}/utils.o

${OUTPUT_DIR}/app:${objs}
	@echo "make $(@)"
	gcc -o $(@) $(^)

${OBJS_DIR}/%.o:${SRC}/%.c
	@echo "make $(@)"
	gcc -o $(@) -c $(<) ${CFLAGS}

.PHONY:clean
clean:
	@echo "clean.."
	-rm -rf ${OBJS_DIR} ${OUTPUT_DIR}/app
