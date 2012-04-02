/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * callbacks.c
 * Copyright (C) nitin chadha 2012 <nitin@linux-2kbl.site>
 * 
 * gtk_oyranos1 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gtk_oyranos1 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pref.h"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"


G_MODULE_EXPORT void
destroy (GtkWidget *widget, GtkWidget* container)
{
	gtk_main_quit ();
}



G_MODULE_EXPORT
gboolean on_btnClose_clicked(GtkWidget *widget,GtkWidget* container)
{
	gtk_main_quit ();
	return FALSE;
}

G_MODULE_EXPORT
void on_btn_DeviceListRefresh_clicked(GtkWidget *widget, GtkWidget* container)
{
	
	g_print("you have pressed refresh button\n");
	//GtkWidget * view = CreateView();
	UpdateView(container);
	//gtk_widget_show(view);
	//gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (container), view);
	g_print("\n i am executed");

}


