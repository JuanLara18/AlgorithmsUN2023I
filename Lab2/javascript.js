function CreateArray(rows, cols) {

    const x = new Array(rows);

    for (var i = 0; i < x.length; i++) {
        x[i] = new Array(cols);
    }
    
    
    for(let i  = 0 ; i < x.length; i++){
        for(let j = 0; j < x[0].length; j++){
            x[i][j] = Math.random()
        }
    }

    return x;
}

function matmul(A, B){
    if (B.length != A[0].length){
        return "It is not possible to multiply matrices";
    }
      
    rows_out = A.length
    cols_out = B[0].length
    out = CreateArray(rows_out, cols_out)
    
    for (let i = 0; i < rows_out; i++){
        for (let j = 0; j <cols_out; j++){
            for(let k = 0; k < B.length; k++ ){
                out[i][j] += A[i][k] * B[k][j]
            }
        } 
    }
            
    return out
}

const a = CreateArray(600, 100)
const b = CreateArray(100, 600)

const tiempo = []

for(let i = 0; i< 10; i++){
    var start = +new Date();

    const x = matmul(a,b)

    var end = +new Date();
    tiempo.push(end - start)
}
console.log("Tiempo en ms 600x100 * 100x600 ")
console.log(tiempo.reduce((accumulator, curr) => accumulator + curr) / 10);

const c = CreateArray(100, 100)
const d = CreateArray(100, 100)

tiempo.length = 0

for(let i = 0; i< 10; i++){
    var start = +new Date();

    const x = matmul(c,d)

    var end = +new Date();
    tiempo.push(end - start)
}
console.log("Tiempo en ms 100x100 * 100x100 ")
console.log(tiempo.reduce((accumulator, curr) => accumulator + curr) / 10);
