let changeLongorShort = () => {
    let dipy = $(".displayer");
    let btn = $(".btn_itlong");
    let _cnt = 0;
    btn.on("click", () => {
        if(_cnt == 1) {
            btn.text("More");
            _cnt = 0;
            dipy.hide();
        } else {
            btn.text("Less");
            dipy.show();
         _cnt = 1;
        }
});
}

changeLongorShort();