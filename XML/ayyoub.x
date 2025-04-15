<window id="main_window" width="200px" height="300px">
    <headerBar id="header-bar" title="welcome" subtitle="Build you UI Application" />

    <class id="main_window" layout="box" space="30%" app>
        <class
            id="widget_space"
            layout="fixed"
            width="299px"
            height="20px"
            visible="true"
            editable="true"
            max-length="100"
            min-length="50"
            background-color="blue"
            foreing-color="white"
        >
            <image src="assets/application/image.png" width="200px" height="200px" opacity="50%" />
        </class>
        <class
            id="main-window"
            layout="fixed"
            width="300px"
            height="399px"
            box-position="main-width"
            colum="1"
            colums-space="24px"
            row = "2"
            
        >
            <class id="main-colum" column="1" layout="flex"> 
                <class id="main-coum" layout="frame" >
                    <class id="widgets.space" layout="box" layout="">

                    </class>
                    
                </class>
            </class>

            <class id="main-main-2" value="for" src="assets/build/for/:id/" >

            </class>

        </class>
    </class>
</window>