let _nowLength_CV = 0;

let addTable = (number) => {
    let dataset = localStorage.getItem(localStorage.key(number));
    dataset = JSON.parse(dataset);
    let table = document.querySelector(".watch_table");
    table.innerHTML += "\n<tr>\n" +
    "<td>" + dataset.cmpname + "</td>\n" +
    "<td>" + dataset.email + "</td>\n" +
    "<td>" + dataset.phone + "</td>\n" +
    "<td>" + dataset.other_info + "</td>\n" +
    "</tr>\n";
}

let forEachLocalStorage_CV = () => {
    for(; _nowLength_CV < localStorage.length; ++_nowLength_CV) {
        addTable(_nowLength_CV);
    } 
}

forEachLocalStorage_CV();