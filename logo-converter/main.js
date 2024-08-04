const fs = require('fs');
const sharp = require('sharp');

(function convertLogo() {
    const logo = 'petrol';
    sharp(`symbols/${logo}.png`)
        .resize({width: 64, height: 64})
        .raw()
        .grayscale()
        .toBuffer({resolveWithObject: true})
        .then((res) => {
            let {data, info} = res;
            let hexArray = [];
            const imageData = []

            for (let i = 0; i < info.height; i++) {
                const arr = [];
                for (let j = i * info.width; j < info.width + i * info.width; j++) {
                    arr.push(data[j])
                }
                imageData.push(arr);
            }

            for (let i = 0; i < info.height; i += 8) {
                const row = [];

                for (let j = 0; j < info.width; j++) {
                    let byte = 0;

                    for (let k = i; k < i + 8; k++) {
                        if (imageData[k][j] > 200)
                            byte = byte | 1 << k - i;
                    }

                    row.push(`0x${byte.toString(16).padStart(2, '0').toUpperCase()}`);
                }
                hexArray.push(`\t{${row}}`);
            }

            fs.writeFileSync(`../arduino/${logo}/${logo}.h`, `#define ROWS ${info.height/8}\n#define COLS ${info.width}\n\nuint8_t logo[ROWS][COLS] = {\n${hexArray.join(",\n")}\n};`);
        })
})()

