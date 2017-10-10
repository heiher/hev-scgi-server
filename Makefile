# Makefile for hev-scgi-server
 
PROJECT=hev-scgi-server

CROSS_PREFIX :=
PP=$(CROSS_PREFIX)cpp
CC=$(CROSS_PREFIX)gcc
STRIP=$(CROSS_PREFIX)strip
PKG_DEPS=glib-2.0 gio-2.0 gmodule-2.0
CCFLAGS=-O3 `pkg-config --cflags $(PKG_DEPS)` -I../hev-scgi-server-library/include
LDFLAGS=`pkg-config --libs $(PKG_DEPS)` -L../hev-scgi-server-library/bin -lhev-scgi-server
 
SRCDIR=src
BINDIR=bin
BUILDDIR=build
 
TARGET=$(BINDIR)/hev-scgi-server

CCOBJS=$(wildcard $(SRCDIR)/*.c)
LDOBJS=$(patsubst $(SRCDIR)%.c,$(BUILDDIR)%.o,$(CCOBJS))
DEPEND=$(LDOBJS:.o=.dep)
 
BUILDMSG="\e[1;31mBUILD\e[0m $<"
LINKMSG="\e[1;34mLINK\e[0m  \e[1;32m$@\e[0m"
STRIPMSG="\e[1;34mSTRIP\e[0m \e[1;32m$@\e[0m"
GENMSG="\e[1;31mGEN\e[0m   $@"
CLEANMSG="\e[1;34mCLEAN\e[0m $(PROJECT)"

V :=
ECHO_PREFIX := @
ifeq ($(V),1)
       undefine ECHO_PREFIX
endif

all : $(TARGET)
 
clean : 
	$(ECHO_PREFIX) $(RM) $(BINDIR)/* $(BUILDDIR)/*
	@echo -e $(CLEANMSG)
 
$(TARGET) : $(LDOBJS)
	$(ECHO_PREFIX) $(CC) -o $@ $^ $(LDFLAGS)
	@echo -e $(LINKMSG)
	$(ECHO_PREFIX) $(STRIP) $@
	@echo -e $(STRIPMSG)
 
$(BUILDDIR)/%.dep : $(SRCDIR)/%.c
	$(ECHO_PREFIX) $(PP) $(CCFLAGS) -MM -MT $(@:.dep=.o) -o $@ $<
 
$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	$(ECHO_PREFIX) $(CC) $(CCFLAGS) -c -o $@ $<
	@echo -e $(BUILDMSG)
 
-include $(DEPEND)

