# XML Style Documentation

# Introduction

---

Working directly with GTK functions can be exhausting and impractical for large and complex projects. Therefore, as part of the GtkFramework project, we present a strategy for working with GTK: writing GTK code in an XML style. This approach simplifies the management of large projects, making the work easier and smoother.

We have assigned tags for each macro we created in this framework, programmed with default values. If you want to change one of the default values, you can write the attribute name followed by `=` and then the value. Note: the value can be a string `"value"`, a numeric value `20`, or an enum like `GTK_WIN_POS_CENTER`, for example.

Any tag must include the required `id` attribute at the beginning; otherwise, it will not work. The `id` must be unique and should be formatted as follows: `<widget id="id_macha_macha" ... >`.

# Our tags database

---

Here is a list of all the tags available in our database, along with their attributes, their possible values, and their default values.

## Windows

---

<aside>
👉

`<window>`

</aside>

| Attributes | Default Values |
| --- | --- |
| id | no default value (your chose) |
| app | no default value (chose app for the main window) |
| **type** | **GTK_WINDOW_TOPLEVEL** |
| **title** | **"Default title"** |
| **width** | **800** |
| **height** | **600** |
| **resizable** | **TRUE** |
| **position** | **GTK_WIN_POS_CENTER** |
| **decorate** | **TRUE** |
| **icon** | **NULL** |
| **opacity** | **1.0** |
| **fullscreen** | **FALSE** |

<aside>
👉

`<header_bar>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **title** | "Default title” |
| **subtitle** | “**Default subtitle”** |
| **icon_path** | **"NULL"** |
| **settings** | **TRUE** |

<aside>
👉

`<scrolled_window>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **horizontal** | **TRUE** |
| **vertical** | **TRUE** |

## Containers

---

<aside>
👉

`<box>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **orientation** | **GTK_ORIENTATION_VERTICAL** |
| **align** | **GTK_ALIGN_CENTER** |
| **spacing** | **0** |

<aside>
👉

`<fixed>`

</aside>

| Attributes | Default Values |
| --- | --- |

<aside>
👉

`<frame>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **title** | **"Default title"** |
| **horizontal_placement** | **0.5** |
| **vertical_placement** | **0.5** |

<aside>
👉

`<**grid**>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **rows_spacing** | 0 |
| **columns_spacing** | 0 |
| **rows_homogeneous** | FALSE |
| **columns_homogeneous** | FALSE |

<aside>
👉

`<paned>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **orientation** | **GTK_ORIENTATION_HORIZONTAL** |
| **default_position** | **100** |
| **show_handle** | TRUE |

<aside>
👉

`<stack>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **switcher** | **NULL** |
| **transition_type** | **GTK_STACK_TRANSITION_TYPE_CROSSFADE** |
| **transition_duration** | 500 |

<aside>
👉

`<switcher>`

</aside>

| Attributes | Default Values |
| --- | --- |
| **spacing** | 0 |
| **buttons_same_size** | TRUE |

Containers are not the elements you see in the graphical interface; rather, as their name suggests, they are containers that hold these elements. The role of containers is to control how the visible widgets are displayed and arranged. The closing tag for each container or widget should be in the following format:

`</container_or_widget add_to_top_container(top_container_id, container_or_widget_id, …..>`

This means that in every closing tag for a container or widget, you must include the container it belongs to.

exemple:

If there is a box containing two other boxes, and each one contains an image, it would look like this:

```html
<box id = "main_box">

    <box id = "box1">

        <image path_image = "assets/ma.png">
        </image add_to_box(box1, image, START, FALSE, FALSE, 10, 0, 0, 0, 0)>

    </box add_to_box(main_box, box1, START, FALSE, FALSE, 10, 0, 0, 0, 0)>

    <box id = "box2">

        <image path_image = "assets/fr.png">
        </image add_to_box(box2, image, START, FALSE, FALSE, 10, 0, 0, 0, 0)>

    </box add_to_box(main_box, box2, START, FALSE, FALSE, 10, 0, 0, 0, 0)>

</box>
```

Each container has its own `add_to` attribute. The `add_to` attribute does not have default values, so you must fill in all its values. This means you need to specify where the container will be added or what element it will belong to, and these values must be explicitly provided for proper functionality.

The `window` is also a container, but it is special in that it can only hold one child, and this child must be added using the `add_to_container(window_id, widget_or_container_id)` function

In addition to the single element that a `window` can hold, you can also add a unique header bar to it. This header bar is a special component that can be attached to the window, but it is limited to just one header bar per window.

exemple:

```html
<!-- Start Window -->
<window id = "window" app = "app" title = "Window Principal" width = 900 height = "660" type = "GTK_WINDOW_TOPLEVEL" position = "GTK_WIN_POS_CENTER">

    <!-- Start header bar -->
    <header_bar id = "header_bar" title = "Ayyoub El Kouri" subtitle = "this is a subtitle" icon_path = "assets/ma.png" settings = TRUE>

        <!-- Start menu button -->
        <menu_button id = "menu_button" label = "click me to see" path = NULL>

            <!-- Start Menu -->
            <menu id = "menu" is_primary = TRUE label = "CLICK">

                <!-- Start menu item1 -->
                <menu_item id = "item1" type = "radio">

                </menu_item add_to_menu(menu, item1)>
                <!-- End menu item1 -->

                <!-- Start menu item2 -->
                <menu_item id = "item2" type = "radio">

                </menu_item add_to_menu(menu, item2)>
                <!-- End menu item2 -->

                <!-- Start item3 -->
                <menu_item id = "item3" type = "radio">

                </menu_item add_to_menu(menu, item3)>
                <!-- End item3 -->

            </menu add_to_menu_button(menu_button, menu)>
            <!-- End Menu -->

        </menu_button add_to_header_bar(header_bar, menu_button, LEFT)>
        <!-- End menu button -->

        <!-- Start button -->
        <button id = "button1" label = "click me">
        </button add_to_header_bar(header_bar, button1, RIGHT)>
        <!-- End button -->

    </header_bar add_header_bar_to_window(window, header_bar)>
    <!-- End header bar -->

    <!-- Start box image -->
    <box id = "image_box" position = GTK_POSITION_>

        <!-- Start image -->
        <image id = "image" path = "assets/ma.png">
        </image add_to_box(image_box, image, START, FALSE, FALSE, 10, 0, 0, 0, 0)>
        <!-- End Image -->

        <!-- Start label -->
        <label id = "label1" font = "consolas" size = "18" label = "hello">
        </label add_to_box(image_box, label1, START, FALSE, FALSE, 10, 0, 0, 0, 0)>
        <!-- End label -->

    </box add_to_container(window, image_box)>
    <!-- End box image -->

</window show_widget(window)>
<!-- End Window -->

```

## Widgets

---

Widgets are the visible elements that you can see in the graphical interface. They are the interactive components, such as buttons, labels, images, text fields, and more, that allow users to interact with the application.

Now that you likely understand the concept, you can check the widgets along with their default values in the `widgets_data_baese.h` file. This file should contain the definitions for each widget and its associated attributes, including the default values for each one. It will provide a clear overview of how the widgets are structured and how they should be configured.

After finishing the style.xml file, it should be translated using the Ayyoub application, which you can generate with the command:

gcc `pkg-config --cflags gtk+-3.0` -o ayyoub *.c `pkg-config --libs gtk+-3.0`

This will generate a file named temp.c alongside main.c. This temp.c is the one you will translate using `make`. You will need to go to the makefile and change `main.c` to `temp.c` in the line:

`SOURCES = $(wildcard $(SRC_DIR)/windows/*.c $(SRC_DIR)/widgets/*.c $(SRC_DIR)/containers/*.c $(TEST_DIR)/test_project_1/*.c $(TEST_DIR)/test_project_2/*.c) main.c data_structures/linked_list/linked_list.c src/*.c`

Then, run `make`.