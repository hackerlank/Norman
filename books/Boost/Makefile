SUBDIRS=timer \
		thread \
		regex \
		shared_ptr

.PHONY:all clean $(SUBDIRS)


all clean:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -j2 -C $@ $(MAKECMDGOALS)

