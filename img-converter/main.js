const fs = require('fs');
const sharp = require('sharp');
const minimalBright = 200;

(function convertLogo() {
    const ext = 'png';
    const logos = ['petrol', 'temperature', 'acum', 'oil'];
    for (const logo of logos) {
        sharp(`symbols/${logo}.${ext}`)
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
                            if (imageData[k][j] > minimalBright)
                                byte = byte | 1 << k - i;
                        }

                        row.push(`0x${byte.toString(16).padStart(2, '0').toUpperCase()}`);
                    }
                    hexArray.push(`\t{${row}}`);
                }

                fs.writeFileSync(`../arduino/${logo}/${logo}.h`, `uint8_t logo[${info.height / 8}][${info.width}] = {\n${hexArray.join(",\n")}\n};`);
            })
    }
})()

