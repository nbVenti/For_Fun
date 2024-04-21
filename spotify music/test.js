const fs = require('fs');

fs.readFile('playtime.json', 'utf8', (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    data = JSON.parse(data);
    data.splice(1,1)
    data.slice(0, 20);
    for (let i = 0; i < data.length; i++) {
        data[i].playtime = data[i].playtime.toFixed(2) + "s" + " " + (data[i].playtime.toFixed(2)/60)/60 + "h";
        // console.log(data[i]);
    }
    fs.writeFile('top20.txt', JSON.stringify(data), (err) => {
        if (err) {
            console.error(err);
            return;
        }
        console.log("File has been written");
    });
});