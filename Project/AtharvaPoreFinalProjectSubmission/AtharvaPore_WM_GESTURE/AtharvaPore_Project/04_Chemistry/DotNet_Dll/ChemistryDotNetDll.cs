using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace Chemistry
{
	//Interface Writen by us
	public interface IChemistry
    {
		float Q1Value { get; set; }
        float Q2Value { get; set; }
        float WorkDoneValue { get; set; }
        float EfficiencyValue { get; set; }
        float CoefficientOfPerformanceRValue { get; set; }
        float CoefficientOfPerformanceACValue { get; set; }

        float Q1(float w, float q2);
        float Q2(float w, float q1);

        float Efficiency(float w, float q1);      //w=WorkDone
        float WorkDone(float q1, float q2);

        float CoefficientOfPerformanceR(float w, float q2);
        float CoefficientOfPerformanceAC(float w, float q1);
    }

    [ClassInterface(ClassInterfaceType.None)]
    public class ChemistryDotNetDll : IChemistry
    {
		public float Q1Value { get; set; }
        public float Q2Value { get; set; }
        public float WorkDoneValue { get; set; }
        public float EfficiencyValue { get; set; }
        public float CoefficientOfPerformanceRValue { get; set; }
        public float CoefficientOfPerformanceACValue { get; set; }

        public ChemistryDotNetDll()
        {
            //Empty
        }

		public float Q1(float w, float q2)
        {
            Q1Value = q2 + w;
            return (Q1Value);
        }

		public float Q2(float w, float q1)
        {
            Q2Value = q1 - w;
            return (Q2Value);
        }

        public float WorkDone(float q1, float q2)
        {
            WorkDoneValue = q1 - q2;
            return (WorkDoneValue);
        }

        public float Efficiency(float w, float q1)
        {
            EfficiencyValue = w / q1;
            return (EfficiencyValue);
        }

        public float CoefficientOfPerformanceR(float w, float q2)
        {
            CoefficientOfPerformanceRValue = q2 / w;
            return (CoefficientOfPerformanceRValue);
        }

        public float CoefficientOfPerformanceAC(float w, float q1)
        {
            CoefficientOfPerformanceACValue = q1 / w;
            return (CoefficientOfPerformanceACValue);
        }
    }


}

