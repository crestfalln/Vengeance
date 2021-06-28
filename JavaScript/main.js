function combi(num, stage = 0)
{
	if(stage == 8)
	{
		if(eval(num.join('')) == 100) 
			console.log(num.join('') + "=100");
	}
	else
	{
		let rep = '';
		for(let i = 0 ; i < 3; i++)
		{
			switch (i) 
			{
				case 0:
					rep = '';
					break;
				case 1:
					rep = '+';
					break;
				case 2:
					rep = '-'
					break;
			}
		let tmp = num[2*stage + 1];
		num[2*stage + 1] = rep;
		combi(num , stage + 1);
		num[2*stage + 1] = tmp;
		}
	}
}

var num = []

for(let i = 1 ; i < 10 ; i++)
{
	num.push(i);
	num.push(' ');
}
num.pop();

combi(num);