DIRS = $(sort $(dir $(wildcard */)))

all:
	@for dir in $(DIRS); do \
		if [ -d $$dir ]; then \
			(cd $$dir && $(MAKE)) || exit 1 ; \
		fi \
	done

clean:
	@for dir in $(DIRS); do \
		if [ -d $$dir ]; then \
			(cd $$dir && $(MAKE) clean) || exit 1 ; \
		fi \
	done


.phony: all clean

