## Process this file with automake to produce Makefile.in

## Created by Anjuta

uidir = $(datadir)/gtk_oyranos/ui
ui_DATA = gtk_oyranos.ui

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(GTK_OYRANOS_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = gtk_oyranos

gtk_oyranos_SOURCES = \
	callbacks.c \
	callbacks.h \
	main.c \
	gtk_oyranos.ui \
	oy_config.h \
	pref.h \
	pref_data.c \
	pref_ui.c

gtk_oyranos_LDFLAGS = \
	-Wl,--export-dynamic

gtk_oyranos_LDADD = $(GTK_OYRANOS_LIBS)

EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/gtk_oyranos
