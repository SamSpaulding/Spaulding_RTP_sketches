
class MathUtils {

    constructor(){

    }

    static spiral(n) {
        // given n an index in the squared spiral
        // p the sum of point in inner square
        // a the position on the current square
        // n = p + a
      
        // Original code: http://jsfiddle.net/davidonet/HJQ4g/
        if (n === 0) return [0, 0, r];
        --n;
        
        var r = Math.floor((Math.sqrt(n + 1) - 1) / 2) + 1;
        
        // compute radius : inverse arithmetic sum of 8+16+24+...=
        var p = (8 * r * (r - 1)) / 2;
        // compute total point on radius -1 : arithmetic sum of 8+16+24+...
      
        var en = r * 2;
        // points by face
      
        var a = (1 + n - p) % (r * 8);
        // compute de position and shift it so the first is (-r,-r) but (-r+1,-r)
        // so square can connect
      
        var pos = [0, 0, r];
        switch (Math.floor(a / (r * 2))) {
            // find the face : 0 top, 1 right, 2, bottom, 3 left
            case 0:
                {
                    pos[0] = a - r;
                    pos[1] = -r;
                }
                break;
            case 1:
                {
                    pos[0] = r;
                    pos[1] = (a % en) - r;
      
                }
                break;
            case 2:
                {
                    pos[0] = r - (a % en);
                    pos[1] = r;
                }
                break;
            case 3:
                {
                    pos[0] = -r;
                    pos[1] = r - (a % en);
                }
                break;
        }

        pos[1] = -1 * pos[1] // change y-axis orientation
        return pos;
    }

    static getPrimesLessThan(n) {
        //implementation of the sieve of Eratosthenes
        let candidateList = []
        for (let i = 2; i < n; i++) {
            candidateList.push(i)
        }

        let topDivisorIndex = Math.floor(Math.sqrt(n)) //we only need to check divisibility up to the square root of n
        //console.log(topDivisorIndex)
        //console.log(candidateList)

        for (let i = 2; i <= topDivisorIndex; i++) {
            candidateList = candidateList.filter((element)=> { return !((element % i) == 0 && element > i);})
            //console.log(i)
            //console.log(candidateList.filter((element)=> { return (element % i) !== 0;}))
        }

        return candidateList;
    }
    
}
